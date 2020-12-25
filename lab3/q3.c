/*
Q3. Write a program to create a chiled process. Display the process IDs of the process, parent and
child (if any) in both parent and child processes.
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void main() {

	pid_t pid = fork();

	if (pid < 0) {
		printf("Fork failed\n");
		exit(-1);
	}

	// no need of if condition as only the parent will wait
	// the child will call printf before the parent always
	wait(NULL);
	printf("My pid is %d and my parents pid is %d\n", getpid(), getppid());
	exit(0);
}