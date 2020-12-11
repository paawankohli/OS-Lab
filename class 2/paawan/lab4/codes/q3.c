/*
Q3. Write a program to create a new hard
link to an existing file and unlink the
same. Accept the old path as input and
print the newpath.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void main() {
	char oldPath[50], newPath[50] = "./tempLink";

	printf("File path: ");
	scanf("%s", oldPath);

	if (link(oldPath, newPath) == -1) {
		printf("Hard Linking error. Code: %d\n", errno);
		exit(1);
	} else {
		printf("Hard Linked. New Path is: %s\n", newPath);
	}

	if (unlink(newPath) == -1) {
		printf("Unlinking error. Code: %d\n", errno);
		exit(1);
	} else {
		printf("Unlinked.\n");
	}
}