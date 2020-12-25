// Q4. Write a C program for reading and writing binary files in C.

#include <stdio.h>
#include <stdlib.h>

int main() {
	// open a binary file in wb mode
	FILE *fptr = fopen("hey.bin", "wb");

	if (fptr == NULL) {
		printf("Error! opening file");
		exit(1);
	}

	int n = 5;
	int num[3];

	num[0] = 34;
	num[1] = 21;
	num[2] = 65;

	fwrite(num, sizeof(num), 1, fptr);
	fclose(fptr);

	// open the same binary file in rb mode
	FILE* fptr2 = fopen("hey.bin", "rb");

	if (fptr2 == NULL) {
		printf("Error! opening file");
		exit(1);
	}

	fread(num, sizeof(num), 1, fptr2);
	fclose(fptr2);

	printf("n1: %d\tn2: %d\tn3: %d\n", num[0], num[1], num[2]);

	return 0;
}