CC=g++ -g -Wall -Wpedantic -lm

%.o: %.cpp
	$(CC) -c -o $@ $< $(OFLAGS)

test: test.cpp todotxt.o
	$(CC) todotxt.o test.cpp -o test

clean:
	rm -f *.o
	rm -f example
