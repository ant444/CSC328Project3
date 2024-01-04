######################################################
#
#   Name: Anthony Nelson
#   Course: CSC 328 010 (Network Programming)
#   Semester/Year: Fall 2023
#   Assignment #3: Threads
#   Short Description: This is the makefile for the
#   project3 executable. It also submits the project
#   to Dr. Schwesinger.
#
######################################################
CC = gcc # compiler for C


all: project3


project3: p3.o
    $(CC) -g -o project3 p3.c -lpthread

p3.o: p3.c
    $(CC) -g -c p3.c

.PHONY: submit clean
submit:
    ~schwesin/bin/submit csc328 project3

clean:
    rm -f *.o
    rm -f project3
