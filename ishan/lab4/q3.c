/*
Q3. Write a program to create a new hard
link to an existing file and unlink the
same. Accept the old path as input and
print the newpath.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<sys/stat.h>
#include<errno.h>

int main() {
	char fPath[100], newPath[100] = "tempLink";
	printf("Enter the file path:\n");
	scanf("%s", fPath);

	int status = link(fPath, newPath);
	if (status == -1) {
		printf("Error occured while linking\n");
		printf("Errno: %d\n", errno);
		exit(1);
	}

	printf("New Path is: %s\n", newPath);
	status = unlink(newPath);

	if (status == -1) {
		printf("Error occured while unlinking\n");
		printf("Errno: %d\n", errno);
		exit(1);
	}

	printf("Unlinking successful\n");
}