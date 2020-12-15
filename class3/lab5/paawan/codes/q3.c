// Q3. Write a C program to implement one side of FIFO.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define FIFO_NAME "/tmp/myfifo"
#define BUFFER_SIZE 20

int main() {

	int mode;
	printf("Enter 1 for write first, 2 for read first: ");
	scanf("%d", &mode);

	if (mode == 1) {
		if (access(FIFO_NAME, F_OK) == -1) {
			int status = mkfifo(FIFO_NAME, 0777);
			if (status != 0) {
				printf("Could not create fifo %s\n", FIFO_NAME);
				exit(EXIT_FAILURE);
			}
		}
	}

	int pipe_fd;

	while (mode != 0) {
		if (mode == 1) {

			char buffer1[BUFFER_SIZE + 1];
			printf("Enter msg: ");
			scanf("%s", buffer1);

			pipe_fd = open(FIFO_NAME, O_WRONLY);
			if (pipe_fd != -1) {
				
				int status = write(pipe_fd, buffer1, BUFFER_SIZE);

				if (status == -1) {
					printf("Error! Can't write to pipe\n");
					exit(EXIT_FAILURE);
				}

				close(pipe_fd);
				mode = 2;

				if (strcmp(buffer1, "quit") == 0) {
					mode = 0;
				}
			}
			else {
				printf("Can't open the pipe\n");
				exit(EXIT_FAILURE);
			}
		}

		else if (mode == 2) {

			char buffer2[BUFFER_SIZE + 1];
			memset(buffer2, '\0', sizeof(buffer2));
		
			pipe_fd = open(FIFO_NAME, O_RDONLY);

			if (pipe_fd != -1) {
				int status;
				do {
					status = read(pipe_fd, buffer2, BUFFER_SIZE);
				} while (status > 0);

				close(pipe_fd);
				mode = 1;
				printf("%s \n", buffer2);

				if (strcmp(buffer2, "quit") == 0) {
					mode = 0;
				}
			}
			else {
				printf("Can't open the pipe\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	exit(EXIT_SUCCESS);
}