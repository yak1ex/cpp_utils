// Automatically generated file, do not edit!
#include <boost/test/auto_unit_test.hpp>

#define YAK_REGEX_REQUIRED
#include "test_config_regex.ipp"

#include <boost/regex.hpp>
#if __cplusplus >= 201103L
#include <regex>
#endif

BOOST_AUTO_TEST_CASE(config_regex)
{
#if __cplusplus >= 201103L
	BOOST_CHECK(
		(boost::is_same<yak::std11::regex, boost::regex >::value && yak_boost_regex_included && yak_use_boost_regex && !yak_std_regex_included && !yak_use_std_regex) ||
		(boost::is_same<yak::std11::regex, std::regex >::value && yak_std_regex_included && yak_use_std_regex && !yak_boost_regex_included && !yak_use_boost_regex)
	);
#else // __cplusplus >= 201103L
	BOOST_CHECK(
		(boost::is_same<yak::std11::regex, boost::regex >::value && yak_boost_regex_included && yak_use_boost_regex && !yak_std_regex_included && !yak_use_std_regex)
	);
#endif // __cplusplus >= 201103L
	BOOST_CHECK(!yak_using_boost_regex);
	BOOST_CHECK(!yak_using_std_regex);
}
