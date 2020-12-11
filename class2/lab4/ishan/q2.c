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

	printf("%s Status Information\n", argv[1]);
	printf("Device Node: %ld\n", sb.st_dev);
	printf("Inode Number: %ld\n", sb.st_ino);
	printf("Mode Bytes: %d\n", sb.st_mode);
	printf("Number of Hard Links: %ld\n", sb.st_nlink);
	printf("Owner User ID: %d\n", sb.st_uid);
	printf("Owner Group ID: %d\n", sb.st_gid);
	printf("File Size: %ld bytes\n", sb.st_size);
	printf("Preffered Block Size: %ld bytes\n", sb.st_blksize);
	printf("Number of Filesystem Blocks: %ld\n", sb.st_blocks);
	char* buff;
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&sb.st_atime));
	printf("Last Access Time: %s\n", buff);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&sb.st_mtime));
	printf("Last Modification Time: %s\n", buff);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&sb.st_mtime));
	printf("Last Change Time: %s\n", buff);

	return 0;
}