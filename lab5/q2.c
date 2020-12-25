// Q2. Demonstrate creation, writing to and reading from a pipe.

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char msg1[] = "this is message #1";
char msg2[] = "this is message #2";
char msg3[] = "this is message #3";

int main(int argc, char *argv[]) {

	// creating a pipe
	int fd[2];
	if (pipe(fd) == -1) {
		printf("Pipe failed\n");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();

	if (pid == -1) {
		printf("Fork failed\n");
		exit(EXIT_FAILURE);
	}

	// parent writes to the pipe
	if (pid != 0) {
		sleep(1);
		write(fd[1], msg1, 100);
		sleep(1);
		write(fd[1], msg2, 100);
		sleep(1);
		write(fd[1], msg3, 100);

		wait(NULL);
	}
	// child reads from the pipe
	else {
		char buff[100];

		for (int i = 0; i < 3; ++i) {
			printf("Message recieved: \n");
			read(fd[0], buff, 100);
			printf("%s\n", buff);
		}

		exit(0);
	}
}