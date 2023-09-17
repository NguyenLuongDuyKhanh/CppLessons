# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o sample.o
	$(CC) $(CFLAGS) -o main main.o sample.o
 
# The main.o target can be written more simply
 
main.o: main.cpp sample.hpp 
	$(CC) $(CFLAGS) -c main.cpp

sample.o: sample.hpp
	$(CC) $(CFLAGS) -c sample.cc