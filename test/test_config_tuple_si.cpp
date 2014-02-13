// Automatically generated file, do not edit!
#include <boost/test/auto_unit_test.hpp>

#define YAK_TUPLE_REQUIRED
#include <tuple>
#include "test_config_tuple.ipp"

BOOST_AUTO_TEST_CASE(config_std_tuple_included)
{
	BOOST_CHECK((boost::is_same<yak::std11::tuple<int>, std::tuple<int> >::value));
	BOOST_CHECK(!yak_boost_tuple_included);
	BOOST_CHECK( yak_std_tuple_included);
	BOOST_CHECK(!yak_use_boost_tuple);
	BOOST_CHECK( yak_use_std_tuple);
	BOOST_CHECK(!yak_using_boost_tuple);
	BOOST_CHECK(!yak_using_std_tuple);
}
