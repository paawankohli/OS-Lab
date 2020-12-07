#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

// argv[0] - binary filename currently being executed
// argv[1] - additional argument 1
// argv[2] - additional argument 2

int main(int argc, char const *argv[]) {

	if (argc != 3) {
		write(2, "There should be 3 arguments specified\n", 38);
		exit(1);
	}

	printf("Search keyword: %s\n", argv[1] );

	int sfd = open(argv[2], O_RDONLY); //source file descriptor
	if (sfd == -1) {
		write(2, "Source file does not exist\n", 27);
		exit(1);
	}

	char line[100] = "";
	char c;
	int no_of_lines = 0;

	while (read(sfd, &c, sizeof(char)) > 0) {
		if (c != '\n') {
			strncat(line, &c, 1);
		}
		else {
			no_of_lines++;

			if (strstr(line, argv[1]) != NULL) {
				printf("Line %d: %s\n", no_of_lines, line );
			}

			line[0] =  '\0';
		}
	}

	close(sfd);
	return 0;
}