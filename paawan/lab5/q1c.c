// Q1. Write a producer and consumer program in C using the FIFO queue. The producer should write a set of 4 integers into the FIFO queue and the consumer should display the 4 integers.

//consumer.c

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

int main() {
	int pipe_fd = open(FIFO_NAME, O_RDONLY);
	int bytes_read = 0;

	if (pipe_fd != -1) {

		int buffer[BUFFER_SIZE + 1];
		memset(buffer, '\0', sizeof(buffer));

		int status;

		do {
			status = read(pipe_fd, buffer, BUFFER_SIZE);
			bytes_read += status;
		} while (status > 0);

		close(pipe_fd);

		for (int i = 0; i < 4; i++) {
			printf("%d ", buffer[i]);
		}
		printf("\n");
	}
	else {
		exit(EXIT_FAILURE);
	}

	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	exit(EXIT_SUCCESS);
}