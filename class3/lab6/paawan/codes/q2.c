// Q2. Implement a parent process, which sends an english alphabet to a child process using shared memory. The child process responds with the next english alphabet to the parent. The parent displays the reply from the child.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

struct shared_use {
	int status;
	char c;
	char cnext;
};

int main() {
	void *shared_memory = (void *)0;
	struct shared_use *commonptr;
	commonptr->status = 0;

	pid_t pid = fork();

	if (pid == -1) {
		printf("Fork failed!!\n");
		exit(EXIT_FAILURE);
	}

	// child
	if (pid == 0) {
		int shmid = shmget((key_t)1234, sizeof(struct shared_use), 0666 | IPC_CREAT);

		if (shmid == -1) {
			printf("shmget failed!!\n");
			exit(EXIT_FAILURE);
		}

		shared_memory = shmat(shmid, (void *)0, 0);

		if (shared_memory == (void *) - 1) {
			printf("shmat failed\n");
			exit(EXIT_FAILURE);
		}

		commonptr = (struct shared_use *)shared_memory;
		
		// wait for the parent to write to shared memory
		while(commonptr->status == 0);

		// child does work
		commonptr->cnext = commonptr->c + 1;

		if (shmdt(shared_memory) == -1) {
			printf("shmdt failed\n");
			exit(EXIT_FAILURE);
		}

		if (shmctl(shmid, IPC_RMID, 0) == -1) {
			printf("shmctl(IP_RMID) failed\n");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}

	// parent
	else {
		int shmid = shmget((key_t)1234, sizeof(struct shared_use), 0666 | IPC_CREAT);

		if (shmid == -1) {
			printf("shmget failed!!\n");
			exit(EXIT_FAILURE);
		}

		shared_memory = shmat(shmid, (void *)0, 0);

		if (shared_memory == (void *) - 1) {
			printf("shmat failed\n");
			exit(EXIT_FAILURE);
		}

		commonptr = (struct shared_use *)shared_memory;

		char ch;
		printf("Enter character: ");
		scanf("%c", &ch);

		commonptr->c = ch;

		// indicates that parent has written to shared memory
		commonptr->status = 1;
		
		printf("Current char: %c\n", commonptr->c);
		
		// wait for the child to finsh its work		
		wait(NULL);
		printf("New char: %c\n", commonptr->cnext);

		if (shmdt(shared_memory) == -1) {
			printf("shmdt failed\n");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}
}