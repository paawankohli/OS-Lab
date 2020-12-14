/*
Q2. Write a program to print out the
complete stat structure of a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main (int argc, char *argv[]) {

	if (argc < 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	struct stat statbuff;
	int flag = stat(argv[1], &statbuff);

	if (flag != 0) {
		printf("Error in stat\n");
		return 1;
	}

	printf("::::::: %s Status Information :::::::\n", argv[1]);
	printf("Device Node: %ld\n", statbuff.st_dev);
	printf("Inode Number: %ld\n", statbuff.st_ino);
	printf("Mode Bytes: %d\n", statbuff.st_mode);
	printf("Number of Hard Links: %ld\n", statbuff.st_nlink);
	printf("Owner User ID: %d\n", statbuff.st_uid);
	printf("Owner Group ID: %d\n", statbuff.st_gid);
	printf("File Size: %ld bytes\n", statbuff.st_size);
	printf("Preffered Block Size: %ld bytes\n", statbuff.st_blksize);
	printf("Number of Filesystem Blocks: %ld\n", statbuff.st_blocks);

	// char* ctime(time_t*)
	printf("Last Access Time: %s", ctime(&statbuff.st_atime));
	printf("Last Modification Time: %s", ctime(&statbuff.st_mtime));
	printf("Last Change Time: %s", ctime(&statbuff.st_mtime));

	return 0;
}