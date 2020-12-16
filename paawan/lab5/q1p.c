// Q1. Write a producer and consumer program in C using the FIFO queue. The producer should write a set of 4 integers into the FIFO queue and the consumer should display the 4 integers.

//producer.c

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF
#define TEN_MEG (1024 * 1024 * 10)

int main() {

	if (access(FIFO_NAME, F_OK) == -1) {
		int status = mkfifo(FIFO_NAME, 0777);
		
		if (status != 0) {
			printf("Could not create fifo %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}

	printf("Enter 4 integers: ");

	int buffer[BUFFER_SIZE + 1];

	for (int i = 0; i < 4; i++) {
		scanf("%d", &buffer[i]);
	}

	int pipe_fd = open(FIFO_NAME, O_WRONLY);
	printf("Process %d result %d\n", getpid(), pipe_fd);

	int bytes_sent = 0;

	if (pipe_fd != -1) {
		while (bytes_sent < TEN_MEG) {

			int status = write(pipe_fd, buffer, BUFFER_SIZE);

			if (status == -1) {
				fprintf(stderr, "Write error on pipe\n");
				exit(EXIT_FAILURE);
			}

			bytes_sent += status;
		}
		close(pipe_fd);
	}
	else {
		exit(EXIT_FAILURE);
	}

	printf("Process %d finished\n", getpid());
	exit(EXIT_SUCCESS);
}