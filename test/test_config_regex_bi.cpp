// Automatically generated file, do not edit!
#include <boost/test/auto_unit_test.hpp>

#define YAK_REGEX_REQUIRED
#include <boost/regex.hpp>
#include "test_config_regex.ipp"

BOOST_AUTO_TEST_CASE(config_boost_regex_included)
{
	BOOST_CHECK((boost::is_same<yak::std11::regex, boost::regex>::value));
	BOOST_CHECK( yak_boost_regex_included);
	BOOST_CHECK(!yak_std_regex_included);
	BOOST_CHECK( yak_use_boost_regex);
	BOOST_CHECK(!yak_use_std_regex);
	BOOST_CHECK(!yak_using_boost_regex);
	BOOST_CHECK(!yak_using_std_regex);
}
