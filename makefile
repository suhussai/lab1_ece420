###
# Designating default compiler and compiler values
###
CC = gcc
CFLAGS = -g -Wall -lpthread -lm

###
# Setting default make
###
default: main
all: serialtester matrixgen main

###
# Process
###
main:
	$(CC) $(CFLAGS) -o main main.c lab1_IO.c

###
# Support
###
serialtester: 
	$(CC) -o serialtester serialtester.c lab1_IO.c

matrixgen:
	$(CC) -o matrixgen matrixgen.c

###
# Clean process
###
clean: 
	rm -f main serialtester matrixgen data_input data_output