CC = g++
CFLAGS = -Wall -Wextra -Wno-unused-parameter -std=c++11 -g

build:
	$(CC) $(CFLAGS) main.cpp -o main

set_dbg: CFLAGS += -DDEBUG

debug: set_dbg

set_dbg: build

run: 
	./main In/in.txt

clean:
	rm -fr main Out/Lab9/* *~
