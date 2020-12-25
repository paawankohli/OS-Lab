#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* thread_code(void* n) {
	printf("Thread running....\n");

	int sum = 0;
	int limit = *((int*)n);

	for (int i = 1; i <= limit; i++)
		sum += i;

	*((int*)n) = sum;
}

void main() {
	pthread_t thread;

	int n;
	printf("No. of elements?\n>> ");
	scanf("%d", &n);

	int ans;
	pthread_create(&thread, 0, &thread_code, (void*)&n);

	pthread_join(thread, NULL);
	printf("Ans is %d\n", n);
}