/*
 CS 365 Operating System (Spring) - Dr. Jie Liu
 Lab 2: Part I
 Author: Stephen K Oliver
 Due Date: 02 May 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "part1.h"
/*
 This is the main function, and it is the entry point for execution.
*/
void main (void)
{
 printf("Start the first part of part 1...\n");
 firstPart(); //do the first part of Part I
 printf("Start the second part of part 1...\n");
 secondPart(); //do the second part of Part I
}
/*
 This function will demonstrate the basic functionality of
 the fork(), wait(), exit(), exec() family-specifically execl(),
 and system("date") functions.
*/
void firstPart (void)
{
 pid_t pid; //memory location to store the pid
 pid = fork(); //fork into 2 processes (initialize pid with fork() to get pid)

 if (pid == 0) //child process
 {
 int i; //counter to be used for exiting the loop
 i = 0; //initialize the counter
 while (1)
 {
 if (i == 1)
 {
 exit(0); //end the child process
 }
 else
 {
 //execute the ls "program" without sending a direct system command
 execl("/bin/ls", "ls", NULL);
 i++; //increment the counter
 }
 }
 }
 else //parent process
 {
 wait(0); //wait until the child process is finished
 system("date"); //print out the system date with the system's date command
 printf("\n"); //empty newline
 }
}
/*
 This function will demonstrate what happens if an in is printed
 as an int, float, and character data type.
*/
void secondPart(void)
{
 int num; //memory for a number (int)
 num = 88; //initialize our number as 88 as specified

 printf("Printing num as an int: %d\n", num); //print the number (int) as an int
 printf("Printing num as a float: %f\n", num); //print the number (int) as a float
 printf("Printing num as a char: %c\n", num); //print the number (int) as a character
}
