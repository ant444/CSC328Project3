/////////////////////////////////////////////////////////
//
//      Name: Anthony Nelson
//      Course: CSC 328 010 (Network Programming)
//      Semester/Year: Fall 2023
//      Assignment #3: Threads
//      Short Description: This file handles all of the
//      command-line arguments, along with what will be
//      done to each thread.
//
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

//Global variable X
int X;

//struct for handling pthreads
typedef struct data {
    int numthreads;
    int *X;
    int *num; //make ptr
    int *nump; // make pointer to a pointer
    int current_thread;
} data_t;

//Function prototypes:
void* routine(void* val);
void programheader(int numthreads, int X, int num, int* nump);


////////////////////////////////////////////////////////////////////////
//
//      Function Name: main
//
//      Description: This function handles the command line
//      arguments and some of the general thread implementation.
//
//      Parameters: argc - number of command line args
//                  argv - specifc command line arg
//
//      Return Value: integer - 0
//
//
////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){


    //checking to see if given the right amount of command line args
    if(argc != 5){
        perror("Give the right amount of info\n");
        exit(-1);
    }
    //storing numthreads to the index 1 of command line
    int numthreads = atoi(argv[1]);

    //
    if(numthreads <= 0 || numthreads >= 11)
    {
     	perror("Number of threads must be 1-10. \n");
        exit(-1);
    }

    X = atoi(argv[2]);
    int num = atoi(argv[3]);
    //nump is a pointer
    int *nump = (int*)malloc(sizeof(int));
    *nump = atoi(argv[4]);
    //error checking for malloc
    if(nump == NULL)
    {
     	fprintf(stderr, "Out of memory\n");
        exit(-1);
    }

    //making array of pthread_t
    pthread_t thd[numthreads];

    //call program header
    programheader(numthreads, X, num, nump);
    //creating array of the structs, yes i know basic name
    data_t arrayofstructs[numthreads];
    for(int i = 0; i < numthreads; i++){
        arrayofstructs[i].numthreads = numthreads;
        arrayofstructs[i].X = &X; //added &
        arrayofstructs[i].num = &num; //added &
        arrayofstructs[i].nump = nump;
        arrayofstructs[i].current_thread = i + 1;

        //if it fails to create the thread, then exit
        if(pthread_create(&thd[i], NULL, routine, (void*)&arrayofstructs[i]) != 0){
            fprintf(stderr, "Failed to create thread: %d\n", i);
            exit(0);
        }
    }

    //Waiting for each thread to finish so that they can join
    for(int i = 0; i < numthreads; i++) {
        pthread_join(thd[i], NULL);
    }



    //frees up memory of nump
    free(nump);
    //final thing before exitting
    printf("This program has completed processing. \n");
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//      Function Name: routine
//
//      Description: This function handles the before and after of output
//          along with data_t implementation and pointer manipulation
//
//
//      Parameters: *val - the value of the pointer
//
//      Return Value: ptr to value
//
//
///////////////////////////////////////////////////////////////////////
void* routine(void* val)
{
    data_t* d = (data_t*)val;
    //outputs before increment
    printf("\n");
    printf("BEFORE increment - Thread Number: %d with TID of %lu, X = %d, num = %d, nump = %d. \n", d->current_thread, pthread_self(), (*(d->X)), (*(d->num)), *(d->nump));
    //add 50 to X
    (*(d->X))+= 50;
    //increment num and nump
    (*(d->num))++;
    (*(d->nump))++;

    printf("AFTER  increment - Thread Number: %d with TID of %lu, X = %d, num = %d, nump = %d. \n", d->current_thread, pthread_self(), (*(d->X)), (*(d->num)), *(d->nump));
    //increment the current thread, go to next one
    d->current_thread++;
    printf("\n");
    pthread_exit(NULL);
}


///////////////////////////////////////////////////////////////////////
//
//      Function Name: programheader
//
//      Description: This function outputs the header for the threads
//      and its user based inputted values
//
//
//      Parameters: numthreads - the number of threads used for output-input
//                           X - global, used in output as X - input
//                         num - is used in output - input
//                        nump - integer pointer - input
//
//
//      Return Value: N/A
//
//
///////////////////////////////////////////////////////////////////////
void programheader(int numthreads, int X, int num, int* nump)
{
    //outputs the basic program header via the rubric
    printf("--------------------------------------------------------------------------\n");
    printf("This program is creating threads... \n");
    printf("The number of threads to create: %d \n", numthreads);
    printf("The current value of X: %d \n", X);
    printf("The current value of num: %d \n", num);
    printf("The current value of nump: %d \n", *nump);
    printf("--------------------------------------------------------------------------\n");
}




