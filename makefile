###
# Designating default compiler and compiler values
###
CC = gcc
CFLAGS = -g -Wall
LIBS = -lpthread -lm

###
# Setting default make
###
default: main
all: serialtester matrixgen main

###
# Process
###
main:
	$(CC) $(CFLAGS) -o main src/main.c src/lab1_IO.c $(LIBS)

###
# Support
###
serialtester: 
	$(CC) -o serialtester src/serialtester.c src/lab1_IO.c

matrixgen:
	$(CC) -o matrixgen src/matrixgen.c

###
# Clean process
###
clean: 
	rm -f main serialtester matrixgen data_input data_output