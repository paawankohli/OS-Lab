/*
Q2. Write a C program to load the binary executable of the previous program in a child process
using the exec system call.
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
		execlp("./o1", "o1", NULL);
	} else {
		wait(NULL);
		printf("Child Complete\n");
		exit(0);
	}
}