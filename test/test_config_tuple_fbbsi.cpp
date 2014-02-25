// Automatically generated file, do not edit!
#if __cplusplus >= 201103L
#include <boost/test/auto_unit_test.hpp>

#define YAK_TUPLE_REQUIRED
#include <boost/tuple/tuple.hpp>
#include <tuple>
#define YAK_FORCE_BOOST_TUPLE
#include "test_config_tuple.ipp"

BOOST_AUTO_TEST_CASE(config_force_boost_tuple_both_tuple_included)
{
	BOOST_CHECK((boost::is_same<yak::std11::tuple<int>, boost::tuple<int> >::value));
	BOOST_CHECK( yak_boost_tuple_included);
#if __cplusplus < 201103L
	BOOST_CHECK( yak_std_tuple_included);
#endif
	BOOST_CHECK( yak_use_boost_tuple);
	BOOST_CHECK(!yak_use_std_tuple);
	BOOST_CHECK(!yak_using_boost_tuple);
	BOOST_CHECK(!yak_using_std_tuple);
}
#endif // __cplusplus >= 201103L
