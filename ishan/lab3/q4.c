/*
Q4. Create a zombie(defunct) child process (a chiled with exit() call, but no corresponding wait() in
the sleeping parent) and allow init process to adopt it (after parent terminates). Run the process as a
background process and run the “ps” command.
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
		pid_t cpid = fork();

		if (cpid < 0) {
			fprintf(stderr, "Fork Failed");
			exit(-1);
		} else if (cpid == 0) {
			sleep(20);
			printf("Grandchild Process\n");
			exit(0);
		} else {
			printf("Child Process\n");
			exit(0);
		}
	} else {
		sleep(30);
		printf("Parent Process\n");
		exit(0);
	}
}