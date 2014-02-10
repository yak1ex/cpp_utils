#ifndef YAK_CONFIG_HPP
#define YAK_CONFIG_HPP

#if defined(__GNUC__)

#if defined(_GLIBCXX_REGEX)
#define YAK_STD_REGEX_INCLUDED
#endif

#elif defined(_MSC_VER)

#if defined(_REGEX_)
#define YAK_STD_REGEX_INCLUDED
#endif

#endif

#if defined(BOOST_RE_REGEX_HPP)
#define YAK_BOOST_REGEX_INCLUDED
#endif

#if defined(YAK_REGEX_REQUIRED) && ! defined(YAK_BOOST_REGEX_INCLUDED) && ! defined(YAK_STD_REGEX_INCLUDED)
#error "std::regex or boost::regex is required"
#endif


#endif
