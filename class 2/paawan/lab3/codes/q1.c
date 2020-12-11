/*
Q1. Write a C program to block a
parent process until the child completes
using a wait system call.
*/

#include <unistd.h> // unix std lib
#include <sys/types.h> // for pid_t
#include <sys/wait.h> // for wait(int*)
#include <stdio.h>
#include <stdlib.h>

void main () {
	pid_t pid = fork();

	if (pid < 0) {
		printf("Fork failed\n");
		exit(-1);
	} else if (pid == 0) {
		int secs = 10;
		printf("Child process running for %d secs.\n", secs);

		for (int i = secs; i > 0 ; i--) {
			printf("%d ", i); fflush(stdout);
			sleep(1);
		}

		printf("\n");
		exit(0);
	} else {
		wait(NULL);
		printf("Child process exited\n");
		exit(0);
	}
}