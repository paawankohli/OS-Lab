/*
Author 	: Paawan Kohli
Reg no 	: 180905416

Q3. Demonstrate  the use of different conversion specifiers
and resulting output to allow the items to be printed.
*/

#include <stdio.h>

void main() {
	int x = -23;
	printf("integer: %d\n", x);

	unsigned int y = 25;
	printf("unsigned integer %u\n", y);

	printf("hexadecimal versions of above two: %#x and %#x\n", x, y);

	float z = 3.14;
	printf("float: %f\n", z);

	double d = 424242.171717;
	printf("double %3.3lf\n", d);


	char c = 'h';
	printf("char: %c\n", c);

	char str[] = "Hello world!";
	printf("string: %s\n", str);
}