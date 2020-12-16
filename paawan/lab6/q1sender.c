// Q1. Process A wants to send a number to Process B. Once recieved, Process B has to check whether the number is palindrome or not. Write a C program to implement this interprocess communication using a message queue.

//sender.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct message {
	long int msgType;
	char msgData[BUFSIZ];
};

int main() {
	struct message m1;
	char buffer[BUFSIZ];
	
	int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	
	if (msgid == -1) {
		printf("msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}

	int run = 1;

	while (run) {

		printf("Enter a number:\t");
		fgets(buffer, BUFSIZ, stdin);
		
		m1.msgType = 1;
		strcpy(m1.msgData, buffer);
		
		if (msgsnd(msgid, (void *)&m1, MAX_TEXT, 0) == -1) {
			printf("msgsnd failed\n");
			exit(EXIT_FAILURE);
		}

		if (strncmp(buffer, "quit", 3) == 0) {
			run = 0;
		}
	}

	exit(EXIT_SUCCESS);
}