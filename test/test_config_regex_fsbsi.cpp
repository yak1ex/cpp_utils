#include <boost/test/auto_unit_test.hpp>

#include <regex>
#include <boost/regex.hpp>
#define YAK_REGEX_REQUIRED
#define YAK_FORCE_STD_REGEX
#include "test_config_regex.ipp"

BOOST_AUTO_TEST_CASE(config_force_std_regex_both_regex_included)
{
	BOOST_CHECK((std::is_same<yak::std11::regex, std::regex>::value));
	BOOST_CHECK( yak_boost_regex_included);
	BOOST_CHECK( yak_std_regex_included);
	BOOST_CHECK(!yak_use_boost_regex);
	BOOST_CHECK( yak_use_std_regex);
	BOOST_CHECK(!yak_using_boost_regex);
	BOOST_CHECK(!yak_using_std_regex);
}
