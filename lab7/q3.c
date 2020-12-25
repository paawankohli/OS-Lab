// Q3. Deadlock

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int num;
sem_t mutex1, mutex2;

void *A(void *arg) {
	sem_wait(&mutex1);
	sleep(1);
	sem_wait(&mutex2);

	num = 2;
	printf("function a executing\nnum = %d\n", num);
	
	sem_post(&mutex2);
	sem_post(&mutex1);
}

void *B(void *arg) {
	sem_wait(&mutex2);
	sleep(1);
	sem_wait(&mutex1);

	num = 1;
	printf("function b executing\nnum = %d\n", num);
	
	sem_post(&mutex1);
	sem_post(&mutex2);
}

int main() {
	pthread_t tid1, tid2;
	
	sem_init(&mutex1, 0, 1);
	sem_init(&mutex2, 0, 1);
	
	pthread_create(&tid1, NULL, A, NULL);
	pthread_create(&tid2, NULL, B, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	return 0;
}

// Terminal has no output due to deadlock