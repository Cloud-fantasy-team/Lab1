CC=g++
CXXFLAGS=-std=c++14 -Wall -Werror

sudoku_basic_test: sudoku_basic_test.o
	@ $(CC) $(CXXFLAGS) -o $@ $^
	./$@

thread_pool_test: thread_pool_test.o
	@ printf "Compiling and testing thread pool...\n"
	@ $(CC) $(CXXFLAGS) $^ -lpthread -o $@
	./thread_pool_test

%.o: src/%.cc
	@ $(CC) $(CXXFLAGS) -c $<

clean:
	@ rm -rf ./*.o
	@ rm -rf ./*test