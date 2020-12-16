/*
Q1. Write a program to find the inode number
of an existing file in a directory. Take the
input as a filename and print the inode
number of the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {

	if (argc < 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	struct stat buff;
	int flag = stat(argv[1], &buff);

	if (flag != 0) {
		printf("Error in stat\n");
		return 1;
	}

	printf("The inode number of %s is %ld.\n", argv[1], buff.st_ino);
	return 0;
}