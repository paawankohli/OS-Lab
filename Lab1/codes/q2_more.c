/*
Author 	: Paawan Kohli
Reg no 	: 180905416

Q2. Write a program to list the files given as arguments,
stopping every 20 buffers until a key is hit.
(a simple version of more UNIX utility)

how to run: ./q2_more filename
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (int argv, char **arg) {

	// must have filename
	if (argv != 2) {
		printf("Invalid syntax.\nFormat: ./q2_more filename \n");
		exit(0);
	}

	char filename[100];
	strcpy(filename, arg[1]);

	printf("File: %s\n", filename);

	int fd = open(filename, O_RDONLY);

	// check if file exists
	if (fd == -1) {
		printf("%s doesn't exist.\n", filename);
		exit(0);
	}

	char buffer[1000] = "";
	char c;
	int currentLine = 1;

	while (read(fd, &c, 1) == 1 && currentLine <= 20) {
		if (c != '\n') {
			strncat(buffer, &c, 1);
		} else {
			printf("Line %d: %s", currentLine, buffer);
			
			if (currentLine != 20) {
				printf("\n");
			}
			
			buffer[0] = '\0';
			currentLine++;
		}
	}

	while (read(fd, &c, 1) == 1) {
		if (c != '\n') {
			strncat(buffer, &c, 1);
		} else {
			// wait for key press before printing
			char keyPress = getchar();
			// read(0, &keyPress, 1);

			printf("Line %d: %s", currentLine, buffer);
			buffer[0] = '\0';
			currentLine++;
		}
	}

	// last line is left in buffer
	char keyPress = getchar();
	// read(0, &keyPress, 1);
	printf("Line %d: %s\n", currentLine, buffer);

	close(fd);

	printf("\n\nEND OF FILE!\n\n");
}