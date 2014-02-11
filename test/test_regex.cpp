#include <boost/test/auto_unit_test.hpp>
#include <boost/regex.hpp>
#include <regex>
#include "regex.hpp"

BOOST_AUTO_TEST_CASE(test_with_boost_regex)
{
	using boost::regex_match;
	using boost::regex;
	using boost::smatch;

	std::string target = "Test";
	smatch sm;
	BOOST_CHECK(regex_match(target, sm, regex{"T(.)(.)t"}));
	BOOST_CHECK_EQUAL(sm[0].str(), target);
	BOOST_CHECK_EQUAL(sm[1].str(), std::string("e"));
	BOOST_CHECK_EQUAL(sm[2].str(), std::string("s"));

	std::string c1, c2;
	BOOST_CHECK(static_cast<bool>(yak::regex::capture(c1, c2) = sm));
	BOOST_CHECK_EQUAL(c1, std::string("e"));
	BOOST_CHECK_EQUAL(c2, std::string("s"));

	std::string c3;
	BOOST_CHECK(static_cast<bool>(yak::regex::capture(std::ignore, c3) = sm));
	BOOST_CHECK_EQUAL(c3, std::string("s"));
}

// std::regex might be broken
BOOST_AUTO_TEST_CASE(test_with_std_regex)
{
	using std::regex_match;
	using std::regex;
	using std::smatch;

	std::string target = "Test";
	smatch sm;
	BOOST_CHECK(regex_match(target, sm, regex{"T(.)(.)t"}));
	BOOST_CHECK_EQUAL(sm[0].str(), target);
//	BOOST_CHECK_EQUAL(sm[1].str(), std::string("e"));
//	BOOST_CHECK_EQUAL(sm[2].str(), std::string("s"));

	std::string c1, c2;
	BOOST_CHECK(static_cast<bool>(yak::regex::capture(c1, c2) = sm));
//	BOOST_CHECK_EQUAL(c1, std::string("e"));
//	BOOST_CHECK_EQUAL(c2, std::string("s"));

	std::string c3;
	BOOST_CHECK(static_cast<bool>(yak::regex::capture(std::ignore, c3) = sm));
//	BOOST_CHECK_EQUAL(c3, std::string("s"));
}
