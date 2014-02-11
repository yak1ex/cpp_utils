#ifndef YAK_UTIL_VARIADIC_HPP
#define YAK_UTIL_VARIADIC_HPP

#include <utility>

namespace yak {
namespace util {

bool any() { return true; }
template<typename T0, typename ... T>
bool any(T0 && t0, T && ... t) { return t0 || ::yak::util::any(std::forward<T>(t)...); }

} // namespace util
} // namespace yak

#endif
