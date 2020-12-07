#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

	if (argc < 2) {
		write(2, "There should atleast 1 file specified\n", 38);
		exit(1);
	}

	for (int i = 1; i < argc; i++) {
		printf("\nReading file %s ...\n", argv[i] );

		int sfd = open(argv[i], O_RDONLY); //source file descriptor

		if (sfd == -1) {
			write(2, "Source file does not exist\n", 27);
			continue;
		}

		char line[100] = "";
		char c, waste;
		int no_of_lines = 0;
		int ctr = 0;

		while (read(sfd, &c, sizeof(char)) > 0) {

			if (c != '\n' && c != '\0') {
				strncat(line, &c, 1);
			} 
			else {
				no_of_lines++;
				ctr++;
				printf("%d: %s\n", no_of_lines, line );
				line[0] =  '\0';

				if (ctr == 20) {
					ctr = 0;
					printf("Enter q(quit) or any other key to continue\n");
					fflush(stdin);

					// while(read(0, &c, 1)==0);

					// c = getchar();

					scanf("%c", &c);

					if (c != '\n') {
						scanf("%c", &waste);
					}

					fflush(stdin);

					if (c == 'q') {
						printf("Exiting...\n");
						fflush(stdin);
						// exit(0);
						// continue;
						break;
					}
				}
			}
		}

		// printf("Closing file %s\n\n", argv[i] );
		// fflush(0);
		close(sfd);
	}

	exit(0);
}