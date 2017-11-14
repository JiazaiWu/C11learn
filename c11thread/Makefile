all:threadexample

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

threadexample:threadexample.o
	$(CC) $(LDFLAGS) -o $@ $^

threadexample.o:threadexample.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm Thread.o Thread