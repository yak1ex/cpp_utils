#ifndef YAK_REGEX_HPP
#define YAK_REGEX_HPP

//#include <regex>
#include <boost/regex.hpp>
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
#if 0
	template<typename BidirectionalIterator,
           typename Alloc = std::allocator< std::sub_match<BidirectionalIterator> > >
  	capture_holder& operator=(const std::match_results<BidirectionalIterator, Alloc>& m)
	{
		assign_imp(m, typename yak::util::make_indices<0, sizeof...(T)>::type());
		return *this;
	}
#else
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
#if 0
	template<std::size_t idx, typename BidirectionalIterator,
           typename Alloc = std::allocator< std::sub_match<BidirectionalIterator> > >
	bool assign_one(const std::match_results<BidirectionalIterator, Alloc>& m)
	{
		std::get<idx>(t) = { m[idx+1].first, m[idx+1].second };
		return m[idx+1].first != m[idx+1].second;
	}
	template<typename BidirectionalIterator,
           typename Alloc = std::allocator< std::sub_match<BidirectionalIterator> >, std::size_t ... indices>
	void assign_imp(const std::match_results<BidirectionalIterator, Alloc>& m, yak::util::indices<indices...>)
	{
		f = yak::util::any(assign_one<indices>(m)...);
	}
#else
	template<std::size_t idx>
	struct ignore_check : std::is_same<
		typename std::remove_cv<
			typename std::tuple_element<idx, std::tuple<T...> >::type
		>::type,
		typename std::remove_cv<decltype(std::ignore)>::type
	> {};
	template<std::size_t idx, typename BidirectionalIterator,
		typename Alloc = std::allocator< boost::sub_match<BidirectionalIterator> > >
	typename std::enable_if<!ignore_check<idx>::value, bool>::type
	assign_one(const boost::match_results<BidirectionalIterator, Alloc>& m) const
	{
		std::get<idx>(t) = { m[idx+1].first, m[idx+1].second };
		return m[idx+1].first != m[idx+1].second;
	}
	template<std::size_t idx, typename BidirectionalIterator,
		typename Alloc = std::allocator< boost::sub_match<BidirectionalIterator> > >
	typename std::enable_if<ignore_check<idx>::value, bool>::type
	assign_one(const boost::match_results<BidirectionalIterator, Alloc>& m) const
	{
		return false;
	}
	template<typename BidirectionalIterator,
           typename Alloc = std::allocator< boost::sub_match<BidirectionalIterator> >, std::size_t ... indices>
	void assign_imp(const boost::match_results<BidirectionalIterator, Alloc>& m, yak::util::indices<indices...>)
	{
		f = yak::util::any(assign_one<indices>(m)...);
	}
#endif
	std::tuple<T&...> t;
	bool f;
};
template<typename ... T>
capture_holder<T...> capture(T& ... t) { return { t... }; }

} // namespace regex
} // namespace yak

#endif
