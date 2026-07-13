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
 
main.o: Ex1_SampleFunctionMain.cpp Ex1_SampleFunction.hpp 
	$(CC) $(CFLAGS) -c Ex1_SampleFunctionMain.cpp

sample.o: Ex1_SampleFunction.hpp
	$(CC) $(CFLAGS) -c Ex1_SampleFunction.cc