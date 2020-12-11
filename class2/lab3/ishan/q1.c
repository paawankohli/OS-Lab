/*
Q1. Write a C program to block a
parent process until the child completes
using a wait system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed");
		exit(-1);
	} else if (pid == 0) {
		execlp("/bin/ls", "ls", NULL);
	} else {
		wait(NULL);
		printf("Child Complete\n");
		exit(0);
	}
}