/*
Author 	: Paawan Kohli
Reg no 	: 180905416

Q1. Write a program to print the lines of a file
that contain a word given as the program argument
(a simple version of grep UNIX utility).

how to run: ./q1_grep searchText filename

*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argv, char **arg) {

	// must have searchText and filename
	if (argv != 3) {
		printf("Invalid syntax.\nFormat: ./q1_grep searchText filename \n");
		exit(0);
	}

	char searchText[100];
	strcpy(searchText, arg[1]);

	char filename[100];
	strcpy(filename, arg[2]);

	printf("\n");
	printf("Search Text: %s \n", searchText);
	printf("Filename: %s \n", filename);
	printf("\n");

	// open file
	int fd = open(filename, O_RDONLY);

	// check if file exists
	if (fd == -1) {
		printf("%s doesn't exist.\n", filename);
		exit(0);
	}

	char buffer[1000] = "";
	char c;

	int currentLine = 1;

	// read char by char
	while (read(fd, &c, 1) == 1) {

		if (c != '\n') {
			// if the char is NOT \n, append it to the string
			strncat(buffer, &c, 1);
		}
		else {
			// if char is append, reading one line is done. Do substring match

			if (strstr(buffer, searchText) != NULL) {
				// print the line if a match is found
				printf("Line %d: %s\n", currentLine, buffer);
			}

			// increment current line count and reset buffer
			currentLine++;
			buffer[0] = '\0';
		}
	}

	// last line is left in buffer
	if (strstr(buffer, searchText) != NULL) {
		// print the line if a match is found
		printf("Line %d: %s\n", currentLine, buffer);
	}

	close(fd);
}