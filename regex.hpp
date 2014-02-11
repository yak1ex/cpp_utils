#ifndef YAK_REGEX_HPP
#define YAK_REGEX_HPP

#define YAK_REGEX_REQUIRED
#include "config.hpp"
#include <string>
#include <iostream>
#include <tuple>

#include "index_tuple.hpp"
#include "variadic.hpp"

namespace yak {
namespace regex {

template<typename ... T>
class capture_holder
{
public:
	capture_holder(T& ... t_) : t(t_...), f(false) {}
	capture_holder(const capture_holder& c) : t(c.t), f(c.f) {}
#ifdef YAK_STD_REGEX_INCLUDED
	template<typename BidirectionalIterator,
           typename Alloc = std::allocator< std::sub_match<BidirectionalIterator> > >
  	capture_holder& operator=(const std::match_results<BidirectionalIterator, Alloc>& m)
	{
		assign_imp(m, typename yak::util::make_indices<0, sizeof...(T)>::type());
		return *this;
	}
#endif
#ifdef YAK_BOOST_REGEX_INCLUDED
	template<typename BidirectionalIterator,
           typename Alloc = std::allocator< boost::sub_match<BidirectionalIterator> > >
  	capture_holder& operator=(const boost::match_results<BidirectionalIterator, Alloc>& m)
	{
		assign_imp(m, typename yak::util::make_indices<0, sizeof...(T)>::type());
		return *this;
	}
#endif
	explicit operator bool() { return f; }
private:
	capture_holder& operator=(const capture_holder&);
	template<std::size_t idx>
	struct ignore_check : std::is_same<
		typename std::remove_cv<
			typename std::tuple_element<idx, std::tuple<T...> >::type
		>::type,
		typename std::remove_cv<decltype(std::ignore)>::type
	> {};
// Called only from assign_imp, therefore the parameter type has already been limited
	template<std::size_t idx, typename U>
	typename std::enable_if<!ignore_check<idx>::value, bool>::type
	assign_one(const U& m) const
	{
		std::get<idx>(t) = { m[idx+1].first, m[idx+1].second };
		return m[idx+1].first != m[idx+1].second;
	}
	template<std::size_t idx, typename U>
	typename std::enable_if<ignore_check<idx>::value, bool>::type
	assign_one(const U& m) const
	{
		return false;
	}
// Called only from operator=, therefore the parameter type has already been limited
	template<typename U, std::size_t ... indices>
	void assign_imp(const U& m, yak::util::indices<indices...>)
	{
		f = yak::util::any(assign_one<indices>(m)...);
	}
	std::tuple<T&...> t;
	bool f;
};
template<typename ... T>
capture_holder<T...> capture(T& ... t) { return { t... }; }

} // namespace regex
} // namespace yak

#endif
