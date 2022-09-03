CXXFLAGS := -g -std=c++11 -Wall -Wextra -Wpedantic -Wfatal-errors #-Werror
# UBSAN:
CXXFLAGS += -fsanitize=undefined
LDFLAGS  := -fsanitize=undefined
CC = $(CXX)

.DELETE_ON_ERROR:
.PHONY: all zip zip_tests test clean

all: hashdemo pish setdemo testParse testScanner

hashdemo: hashdemo.o
pish: pish.o Scanner.o Parse.o
setdemo: setdemo.o
testParse: testParse.o Scanner.o Parse.o
testScanner: testScanner.o Scanner.o

hashdemo.o: hashdemo.cpp hash.h
pish.o: pish.cpp hash.h Scanner.h Parse.h
Scanner.o: Scanner.cpp Scanner.h
Parse.o: Parse.cpp Parse.h
setdemo.o: setdemo.cpp set.h
testParse.o: testParse.cpp Scanner.h Parse.h
testScanner.o: testScanner.cpp Scanner.h

test: pish testParse
	cp $^ pish_tests/
	$(MAKE) -C hash_test/ $@
	$(MAKE) -C pish_tests/ $@

zip_tests: makefile pish_tests/ hash_test/
	$(MAKE) clean
	zip -r tests.zip $^

zip: hash.h pish.cpp
	zip a5.zip $^

clean:
	rm -f *.o hashdemo pish setdemo testParse testScanner
	$(MAKE) -C hash_test/ $@
	$(MAKE) -C pish_tests/ $@
