CC=g++ -g -Wall -lm

%.o: %.cpp
	$(CC) -c -o $@ $< $(OFLAGS)

example: example.cpp todotxt.o
	$(CC) todotxt.o example.cpp -o example

clean:
	rm -f *.o
	rm -f example
