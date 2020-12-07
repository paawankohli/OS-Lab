#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[]) {

	// declare different data types
	int x = -23;
	unsigned int y = 25;
	float z = 3.14;
	double d = 424242.171717;
	char c = 'h';
	char str[] = "Hello world!";

	errno = EPERM;

	printf("Integer: %d\n", x);
	printf("unsigned Integer %u\n", y);
	printf("Hexadecimal versionsof both: %#x %#x\n", x, y);
	printf("float: %f\n", z);
	printf("double %3.3lf\n", d);
	printf("STRING %s\n", str);
	printf("CHAR %c\n", c);
	printf("ERR %m\n");

	return 0;
}