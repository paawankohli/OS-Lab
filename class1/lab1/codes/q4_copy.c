/*
Author 	: Paawan Kohli
Reg no 	: 180905416

Q4. Write a program to copy character by character
copy is accomplished using calls to the functions
referenced in stdio.h

how to run: ./q4_copy sourceFilename destinationFilename
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argv, char ** arg) {

	// must have searchText and filename
	if (argv != 3) {
		printf("Invalid syntax.\nFormat: ./q4_copy sourceFilename destinationFilename \n");
		exit(0);
	}

	char srcFile[100], dstFile[100];
	strcpy(srcFile, arg[1]);
	strcpy(dstFile, arg[2]);

	FILE* in = fopen(srcFile, "r");
	FILE* out = fopen(dstFile, "w");

	char c;

	while ( (c = fgetc(in)) != EOF) {
		fputc(c, out);
	}

	fclose(in);
	fclose(out);

	printf("Copying successful!\n");
}
