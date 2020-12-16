#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
	char path[50];
	printf("Enter path: ");
	scanf("%s", path);

	struct dirent **namelist;
    int n = scandir(path, &namelist, NULL, alphasort);
    
    if (n == -1) {
    	perror("scandir fail");
    	exit(EXIT_FAILURE);
    }

    for (int i = 0 ; i < n ; i++) {
        if (strcmp(namelist[i]->d_name, ".") == 0 || strcmp(namelist[i]->d_name, "..") == 0)
            continue;

        struct stat buff;
        stat(namelist[i]->d_name, &buff);
            
        if (S_ISDIR(buff.st_mode))
    	   printf("%s\n", namelist[i]->d_name);
    }

    char name[50];
    char cmd;

    while (1) {
        printf("Enter dir to delete or quit: ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) 
            break;

        printf("Are you sure? (Y/N): ");
        scanf("%c", &cmd);

        if (cmd == 'N') {
            printf("Not deleted!\n");
            continue;
        } else if (cmd == 'Y') {
            rmdir(name);
            printf("Deleted!\n");
        } 
    }
}
