/*
Q2. Write a C program to load the binary executable of the previous program in a child process
using the exec system call.
*/

#include <unistd.h> // unix std lib
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void main() {
	pid_t pid = fork();

	if (pid < 0) {
		printf("Fork failed\n");
		exit(-1);
	} else if (pid == 0) {
		execvp("./q1", NULL);
		exit(0);
	} else {
		wait(NULL);
		printf("All done.\n");
		exit(0);
	}
}