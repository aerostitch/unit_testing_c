SOURCE_DIR=src
CPPFLAGS += -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0

all: clean cpputest

.PHONY: cpputest clean googletest

obj:
	gcc -g -Wall -c $(SOURCE_DIR)/search.c $(CPPFLAGS)

cunit: obj
	# apt install libcunit1-dev
	gcc -g -Wall cunit/search.c search.o -lcunit -I$(SOURCE_DIR) $(CPPFLAGS) -o test_search_cunit
	./test_search_cunit && rm search.o test_search_cunit

cpputest:
	# apt install cpputest nvptx-tools
	make -C cpputest gcov

googletest:
	# sudo apt-get install libgtest-dev libgmock-dev googletest google-mock googletest-tools
	mkdir -p gtest/build && cd gtest/build; cmake .. && make all test && ./runUnitTests ; cd - && rm -rf gtest/build

clean:
	rm -rf search.o test_search_cunit
	make -C cpputest clean
