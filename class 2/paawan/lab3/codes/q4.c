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
		printf("Fork failed\n");
		exit(-1);
	} else if (pid == 0) {
		printf("Old Parent ID: %d\n", getppid());
		sleep(2);
		printf("New Parent ID: %d\n", getppid());
		exit(0);
	} else {
		sleep(1);
	}
}