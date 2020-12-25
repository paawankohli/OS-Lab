#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *prime(void* arr) {
	int low = *((int*)arr);
	int high = *(((int*)(arr + sizeof(int))));


	printf("Prime numbers: ");

	for (int i = low; i <= high; i++) {
		int flag = 0;
		for (int j = 2; j <= i / 2; j++) {
			if ((i % j) == 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			printf("%d ", i);
	}

	printf("\n");
}

int main() {
	pthread_t thread;

	printf("Enter the limits:\n>> ");
	int arr[2];
	scanf("%d %d", &arr[0], &arr[1]);

	pthread_create(&thread, 0, &prime, (void*)arr);

	pthread_join(thread, NULL);
}