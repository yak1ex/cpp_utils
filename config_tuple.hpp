#ifndef YAK_CONFIG_TUPLE_HPP
#define YAK_CONFIG_TUPLE_HPP

#ifdef YAK_USE_BOOST_TUPLE
#define NS ::boost
#include <boost/type_traits/integral_constant.hpp>
#else /* YAK_USE_STD_TUPLE */
#define NS ::std
#endif

namespace yak { namespace std11 {

using NS::tuple;

using NS::make_tuple;
using NS::tie;

#ifdef YAK_USE_BOOST_TUPLE
using ::boost::tuples::ignore;
template <class T>
struct tuple_size
   : public ::boost::integral_constant
   < ::std::size_t, ::boost::tuples::length<T>::value>
{};

template < int I, class T>
struct tuple_element
{
   typedef typename boost::tuples::element<I,T>::type type;
};
#else
using ::std::ignore;
using ::std::tuple_size;
using ::std::tuple_element;
#endif

using NS::get;

}}

#undef NS

#endif
