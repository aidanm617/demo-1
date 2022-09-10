
CLANG_FLAGS = -std=c++17 -Wall

GTEST_FLAGS = -lpthread -lgtest_main -lgtest

# determine Python version, need at least 3.7
PYTHON=python3
ifneq (, $(shell which python3.7))
	PYTHON=python3.7
endif
ifneq (, $(shell which python3.8))
	PYTHON=python3.8
endif

build: Book_test

test: Book_test
	./Book_test

grade: grade.py Book_test
	${PYTHON} grade.py

Book_test:  Book.hpp Book.cpp Book_test.cpp
	clang++ ${CLANG_FLAGS} ${GTEST_FLAGS} Book.cpp Book_test.cpp -o Book_test

clean:
	rm -f gtest.xml results.json Book_test Book_timing
