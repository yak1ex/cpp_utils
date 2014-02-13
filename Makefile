CXXFLAGS=-std=c++11 -I. -Itest -Wall -pedantic
LDFLAGS=-L/usr/local/lib
LIBS=-lboost_regex-mt

all:
	@echo If you want to test, please type "'make test'"

clean:
	rm -rf test/*.o test/*.exe

gen:
	perl test/gen_test_config.pl regex,boost/regex.hpp,regex tuple,boost/tuple/tuple.hpp,tuple,int

.PHONY: test all clean gen

test: test/testrunner
	./test/testrunner --log_level=warning

test/testrunner: $(patsubst test%.cpp,test%.o,$(wildcard test/test*.cpp))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

test/test_regex.o: test/test_regex.cpp regex.hpp
