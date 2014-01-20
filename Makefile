CC=g++ -g -Wall -lm

%.o: %.cpp
	$(CC) -c -o $@ $< $(OFLAGS)

test: test.cpp todotxt.o
	$(CC) todotxt.o example.cpp -o example

clean:
	rm -f *.o
	rm -f example
