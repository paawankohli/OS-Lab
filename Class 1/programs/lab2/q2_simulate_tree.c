//Simulate tree
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void printdir(char *dir, int depth) {
	struct dirent* entry;
	struct stat statbuf;

	DIR* dp = opendir(dir);

	if (dp == NULL) {
		fprintf(stderr, "cannot open directory: %s\n", dir);
		return;
	}

	chdir(dir);

	while ((entry = readdir(dp)) != NULL) {

		lstat(entry->d_name, &statbuf);

		if (S_ISDIR(statbuf.st_mode)) {

			if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
				continue;
			}

			printf("%*s%s/\n", depth, " ", entry->d_name);
			printdir(entry->d_name, depth + 4);
		} 
		else {
			printf("%*s%s/\n", depth, " ", entry->d_name);
		}

	}

	chdir("..");
	closedir(dp);
}

int main(int argc, char const *argv[]) {

	if (argc == 2) {
		char *dir = (char*)argv[1];
		printdir(dir, 0);
	}
	else {
		printdir("/home", 0);
	}

	printf("Exiting...done.\n");

	exit(0);
}