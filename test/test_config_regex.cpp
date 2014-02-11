#include <boost/test/auto_unit_test.hpp>

#define YAK_REGEX_REQUIRED
#include "test_config_regex.ipp"

#include <boost/regex.hpp>
#include <regex>

BOOST_AUTO_TEST_CASE(config_regex)
{
	BOOST_CHECK(
		(std::is_same<yak::std11::regex, boost::regex>::value && yak_boost_regex_included && yak_use_boost_regex && !yak_std_regex_included && !yak_use_std_regex) ||
		(std::is_same<yak::std11::regex, std::regex>::value && yak_std_regex_included && yak_use_std_regex && !yak_boost_regex_included && !yak_use_boost_regex)
	);
	BOOST_CHECK(!yak_using_boost_regex);
	BOOST_CHECK(!yak_using_std_regex);
}
