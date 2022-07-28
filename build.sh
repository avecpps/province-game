#!/bin/sh
g++ -c src/*.cpp
g++ *.o -o output -lncurses
