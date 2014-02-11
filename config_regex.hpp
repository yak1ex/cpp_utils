#ifndef YAK_CONFIG_REGEX_HPP
#define YAK_CONFIG_REGEX_HPP

#ifdef YAK_USE_BOOST_REGEX
#define NS ::boost
#else /* YAK_USE_STD_REGEX */
#define NS ::std
#endif

namespace yak { namespace std11 {

namespace regex_constants {

using NS::regex_constants::syntax_option_type;
using NS::regex_constants::icase;
using NS::regex_constants::nosubs;
using NS::regex_constants::optimize;
using NS::regex_constants::collate;
using NS::regex_constants::ECMAScript;
using NS::regex_constants::basic;
using NS::regex_constants::extended;
using NS::regex_constants::awk;
using NS::regex_constants::grep;
using NS::regex_constants::egrep;

using NS::regex_constants::match_flag_type;
using NS::regex_constants::match_default;
using NS::regex_constants::match_not_bol;
using NS::regex_constants::match_not_eol;
using NS::regex_constants::match_not_bow;
using NS::regex_constants::match_not_eow;
using NS::regex_constants::match_any;
using NS::regex_constants::match_not_null;
using NS::regex_constants::match_continuous;
using NS::regex_constants::match_prev_avail;
using NS::regex_constants::format_default;
using NS::regex_constants::format_sed;
using NS::regex_constants::format_no_copy;
using NS::regex_constants::format_first_only;

using NS::regex_constants::error_type;
using NS::regex_constants::error_collate;
using NS::regex_constants::error_ctype;
using NS::regex_constants::error_escape;
using NS::regex_constants::error_backref;
using NS::regex_constants::error_brack;
using NS::regex_constants::error_paren;
using NS::regex_constants::error_brace;
using NS::regex_constants::error_badbrace;
using NS::regex_constants::error_range;
using NS::regex_constants::error_space;
using NS::regex_constants::error_badrepeat;
using NS::regex_constants::error_complexity;
using NS::regex_constants::error_stack;

} // namespace regex_constants

using NS::regex_error;

using NS::regex_traits;

using NS::basic_regex;
using NS::regex;
using NS::wregex;

using NS::sub_match;
using NS::match_results;
using NS::cmatch;
using NS::wcmatch;
using NS::smatch;
using NS::wsmatch;

using NS::regex_match;
using NS::regex_search;
using NS::regex_replace;

using NS::regex_iterator;
using NS::cregex_iterator;
using NS::wcregex_iterator;
using NS::sregex_iterator;
using NS::wsregex_iterator;

using NS::regex_token_iterator;
using NS::cregex_token_iterator;
using NS::wcregex_token_iterator;
using NS::sregex_token_iterator;
using NS::wsregex_token_iterator;

}}

#undef NS

#endif
