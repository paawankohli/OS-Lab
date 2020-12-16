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
	struct stat sb;
	int ret;

	if (argc < 2) {
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}

	ret = stat(argv[1], &sb);

	if (ret) {
		perror ("stat");
		return 1;
	}

	printf("The inode number of %s is %ld\n", argv[1], sb.st_ino);
	return 0;
}