#include <unistd.h>
#include <sys/types.h> // for pid_t
#include <stdio.h>
#include <sys/wait.h> // for wait(int*)

// pid_t fork(void)
// void wait(int*)
// sleep(int sec)
// exit(int)

// exec - replaces current process with a new process
// variations - execl/execv/execle/execve/execlp/exevp


void main () {
	pid_t pid = fork();

	if (pid == 0) {
		for (int i = 0 ; i < 5; i++) {
			printf("This is the child process\n");
			sleep(2);
		}
	} else if (pid == -1) {
		printf("Error\n");
	} else {
		int status;
		sleep(1);
		for (int i = 0 ; i < 2; i++) {
			printf("This is the parent process\n");
			sleep(2);
		}
		wait(&status);
		printf("Child returned %d\n", status);
	}
}