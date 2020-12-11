#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void printSpace(int depth) {
	for (int i = 0 ; i < depth ; i++) {
		printf("    ");
	}
}

void printRecurrsive(char *dir, int depth) {

	DIR* fd = opendir(dir);

	if (fd == NULL) {
		fprintf(stderr, "Error! Can't open %s\n", dir);
		exit(0);
	}

	chdir(dir);

	struct dirent* entry;
	struct stat buffer;

	while ((entry = readdir(fd)) != NULL) {
		lstat(entry->d_name, &buffer);

		if (S_ISDIR(buffer.st_mode)) {

			if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
				continue;
			}

			// print
			printSpace(depth);
			printf("%s \n", entry->d_name);
			
			printRecurrsive(entry->d_name, depth + 1);
		}
		else {

			// print
			printSpace(depth);
			printf("%s \n", entry->d_name);
		}
	}

	chdir("..");
	closedir(fd);
}

void main(int argv, char** arg) {

	// must have path
	if (argv != 2) {
		printf("Invalid syntax.\nFormat: ./q2 path \n");
		exit(0);
	}

	printRecurrsive(arg[1], 0);
}