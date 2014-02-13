// Automatically generated file, do not edit!
#include <boost/test/auto_unit_test.hpp>

#define YAK_TUPLE_REQUIRED
#include "test_config_tuple.ipp"

#include <boost/tuple/tuple.hpp>
#include <tuple>

BOOST_AUTO_TEST_CASE(config_tuple)
{
	BOOST_CHECK(
		(boost::is_same<yak::std11::tuple<int>, boost::tuple<int> >::value && yak_boost_tuple_included && yak_use_boost_tuple && !yak_std_tuple_included && !yak_use_std_tuple) ||
		(boost::is_same<yak::std11::tuple<int>, std::tuple<int> >::value && yak_std_tuple_included && yak_use_std_tuple && !yak_boost_tuple_included && !yak_use_boost_tuple)
	);
	BOOST_CHECK(!yak_using_boost_tuple);
	BOOST_CHECK(!yak_using_std_tuple);
}
