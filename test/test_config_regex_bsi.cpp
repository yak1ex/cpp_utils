#include <boost/test/auto_unit_test.hpp>

#include <regex>
#include <boost/regex.hpp>
#define YAK_REGEX_REQUIRED
#include "test_config_regex.ipp"

BOOST_AUTO_TEST_CASE(config_both_regex_included)
{
	BOOST_CHECK(
		(std::is_same<yak::std11::regex, boost::regex>::value && yak_use_boost_regex && !yak_use_std_regex) ||
		(std::is_same<yak::std11::regex, std::regex>::value && yak_use_std_regex && !yak_use_boost_regex)
	);
	BOOST_CHECK(yak_boost_regex_included);
	BOOST_CHECK(yak_std_regex_included);
	BOOST_CHECK(!yak_using_boost_regex);
	BOOST_CHECK(!yak_using_std_regex);
}
