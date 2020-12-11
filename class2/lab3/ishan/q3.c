/*
Q3. Write a program to create a chiled process. Display the process IDs of the process, parent and
child (if any) in both parent and child processes.
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
		printf("Child Process\n");
		pid_t cpid = getpid();
		pid_t ppid = getppid();
		printf("Parent PID = %d\nChild PID = %d", ppid, cpid);
	} else {
		wait(NULL);
		printf("Child Complete\n");
		printf("Parent Process\n");
		pid_t ppid = getpid();
		printf("Parent PID = %d\nChild PID = %d", ppid, pid);
		exit(0);
	}
}