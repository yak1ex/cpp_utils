#include "config.hpp"
#include <type_traits>

const int yak_boost_regex_included =
#if defined(YAK_BOOST_REGEX_INCLUDED)
1
#else
0
#endif
;
const int yak_std_regex_included =
#if defined(YAK_STD_REGEX_INCLUDED)
1
#else
0
#endif
;
const int yak_use_boost_regex =
#if defined(YAK_USE_BOOST_REGEX)
1
#else
0
#endif
;
const int yak_use_std_regex =
#if defined(YAK_USE_STD_REGEX)
1
#else
0
#endif
;
const int yak_using_boost_regex =
#if defined(YAK_USING_BOOST_REGEX)
1
#else
0
#endif
;
const int yak_using_std_regex =
#if defined(YAK_USING_STD_REGEX)
1
#else
0
#endif
;
