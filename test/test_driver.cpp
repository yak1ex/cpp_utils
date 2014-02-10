#include <cstddef>
#include <stdarg.h>
extern "C" int mkstemp(char *templ);
extern "C" int snprintf(char * s, std::size_t n, const char* format, ...);
extern "C" int vsnprintf(char *str, std::size_t size, const char *format, va_list ap);
extern "C" int putenv(char *string);
#define BOOST_AUTO_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <boost/test/auto_unit_test.hpp>
