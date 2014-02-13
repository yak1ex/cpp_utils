#if defined(__GNUC__)

#    if defined(_GLIBCXX_REGEX)
#        define YAK_STD_REGEX_INCLUDED
#    endif
#    if defined(_GLIBCXX_TUPLE)
#        define YAK_STD_TUPLE_INCLUDED
#	 endif

#elif defined(_MSC_VER)

#    if defined(_REGEX_)
#        define YAK_STD_REGEX_INCLUDED
#    endif
#    if defined(_TUPLE_)
#        define YAK_STD_TUPLE_INCLUDED
#    endif

#endif

#if defined(BOOST_RE_REGEX_HPP)
#    define YAK_BOOST_REGEX_INCLUDED
#endif
#if defined(BOOST_TUPLE_HPP)
#    define YAK_BOOST_TUPLE_INCLUDED
#endif

#if defined(YAK_REGEX_REQUIRED)

#    if defined(YAK_FORCE_STD_REGEX)
#        if defined(YAK_FOCE_BOOST_REGEX)
#            error "Both of std::regex and boost::regex are required"
#        endif
#        define YAK_USING_STD_REGEX
#    elif defined(YAK_FORCE_BOOST_REGEX)
#        define YAK_USING_BOOST_REGEX
#    elif ! (defined(YAK_BOOST_REGEX_INCLUDED) ^ defined(YAK_STD_REGEX_INCLUDED))
#        if (defined(__GNUC__)  && __cplusplus >= 201103L && (__GNUC_MAJOR__ >= 5 || \
            (__GNUC_MAJOR__ == 4 && __GNUC_MINOR__ >= 9))) || (defined(_MSC_VER) && _MSC_VER >= 1500)
#            define YAK_USING_STD_REGEX
#        else
#            define YAK_USING_BOOST_REGEX
#        endif
#    elif defined(YAK_BOOST_REGEX_INCLUDED)
#        define YAK_USING_BOOST_REGEX
#    else /* defined(YAK_STD_REGEX_INCLUDED) */
#        define YAK_USING_STD_REGEX
#    endif

#endif

#if defined(YAK_USING_STD_REGEX) && ! defined(YAK_USE_STD_REGEX)
#    if defined(YAK_USE_BOOST_REGEX)
#        error "std::regex is forced but boost::regex has already been selected"
#    endif
#    if ! defined(YAK_STD_REGEX_INCLUDED)
#        include <regex>
#        define YAK_STD_REGEX_INCLUDED
#    endif
#    undef YAK_USING_STD_REGEX
#    define YAK_USE_STD_REGEX
#    include "config_regex.hpp"
#endif

#if defined(YAK_USING_BOOST_REGEX) && ! defined(YAK_USE_BOOST_REGEX)
#    if defined(YAK_USE_STD_REGEX)
#        error "boost::regex is forced but std::regex has already been selected"
#    endif
#    if ! defined(YAK_BOOST_REGEX_INCLUDED)
#        include <boost/regex.hpp>
#        define YAK_BOOST_REGEX_INCLUDED
#    endif
#    undef YAK_USING_BOOST_REGEX
#    define YAK_USE_BOOST_REGEX
#    include "config_regex.hpp"
#endif

#if defined(YAK_TUPLE_REQUIRED)

#    if defined(YAK_FORCE_STD_TUPLE)
#        if defined(YAK_FOCE_BOOST_TUPLE)
#            error "Both of std::tuple and boost::tuple are required"
#        endif
#        define YAK_USING_STD_TUPLE
#    elif defined(YAK_FORCE_BOOST_TUPLE)
#        define YAK_USING_BOOST_TUPLE
#    elif ! (defined(YAK_BOOST_TUPLE_INCLUDED) ^ defined(YAK_STD_TUPLE_INCLUDED))
#        if (defined(__GNUC__)  && __cplusplus >= 201103L && (__GNUC_MAJOR__ >= 5 || \
            (__GNUC_MAJOR__ == 4 && __GNUC_MINOR__ >= 3))) || (defined(_MSC_VER) && _MSC_VER >= 1500)
#            define YAK_USING_STD_TUPLE
#        else
#            define YAK_USING_BOOST_TUPLE
#        endif
#    elif defined(YAK_BOOST_TUPLE_INCLUDED)
#        define YAK_USING_BOOST_TUPLE
#    else /* defined(YAK_STD_TUPLE_INCLUDED) */
#        define YAK_USING_STD_TUPLE
#    endif

#endif

#if defined(YAK_USING_STD_TUPLE) && ! defined(YAK_USE_STD_TUPLE)
#    if defined(YAK_USE_BOOST_TUPLE)
#        error "std::tuple is forced but boost::tuple has already been selected"
#    endif
#    if ! defined(YAK_STD_TUPLE_INCLUDED)
#        include <tuple>
#        define YAK_STD_TUPLE_INCLUDED
#    endif
#    undef YAK_USING_STD_TUPLE
#    define YAK_USE_STD_TUPLE
#    include "config_tuple.hpp"
#endif

#if defined(YAK_USING_BOOST_TUPLE) && ! defined(YAK_USE_BOOST_TUPLE)
#    if defined(YAK_USE_STD_TUPLE)
#        error "boost::tuple is forced but std::tuple has already been selected"
#    endif
#    if ! defined(YAK_BOOST_TUPLE_INCLUDED)
#        include <boost/tuple/tuple.hpp>
#        define YAK_BOOST_TUPLE_INCLUDED
#    endif
#    undef YAK_USING_BOOST_TUPLE
#    define YAK_USE_BOOST_TUPLE
#    include "config_tuple.hpp"
#endif
