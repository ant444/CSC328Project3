# CSC328Project3

Program Outline

I. Declare variables

Declare a global integer variable named X.
Declare an integer variable named num in the main function.
Declare an integer pointer variable, nump in the main function; the memory for the pointed to value must be in the heap.
Process command line arguments
Accept four command-line arguments:

The number of processes to create between 1 and 10 inclusive.
Initial value to assign to X.
Initial value to assign to num.
Initial value to assign to numps dereferenced value.
Initialize the variables declared in part I.
Assign the initial value of X.
Assign the initial value of num.
Assign the initial value that nump points to.
Create threads
Print a statement indicating the program is creating threads, the number of threads to create, the current value of X, the current value of num, and the current value of nump.

Create a number threads corresponding to the first command line argument. Each sub-thread must perform processing as specified below.

V. End the program

Print a statement indicating the program has completed processing.
Clean up any necessary resources.
Thread Processing

The main thread must:

Coordinate the sub-threads
Each sub-thread must do the following:

Print the following information: the text string “BEFORE increment”, thread number, thread ID, value of X, value of num, and value of nump.

Add 50 to the value of X.

Increment the value of num.

Increment the value that nump points to.

Print the following information: the text string “AFTER increment”, thread number, thread ID, value of X, value of num, and value of nump.

End the thread.

The print statements for a sub-thread should follow this format assuming the command line arguments for X, num, and nump are 500, 5, and 10 respectively. (note some of the values may be different):

BEFORE increment: Thread number 1 with TID of 3795580672: X = 500, num = 5, nump = 10
AFTER increment: Thread number 1 with TID of 3795580672: X = 550, num = 6, nump = 11
Makefile Rules

The following rules must be added to the provided Makefile:

Add a rule to build an executable named project3 from your C program. This must be the default action of the Makefile. Note that the pthread library needs to be linked in order for the program to compile.

Add a rule called clean to remove any temporary files and the project3 executable.

