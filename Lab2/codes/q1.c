// Simulate ls -l

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include<string.h>

void main(int agrv, char ** arg) {
    DIR *mydir = opendir(arg[1]);

    struct dirent *myfile;
    struct stat fileStat;
    stat(".", &fileStat);

    while ((myfile = readdir(mydir)) != NULL) {
        stat(myfile->d_name, &fileStat);

        if (strcmp(".", myfile->d_name) == 0 || strcmp("..", myfile->d_name) == 0)
            continue;
        else {
            printf("Filename: %s\n", myfile->d_name);
            printf("Permsission: ");
            printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
            printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
            printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
            printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
            printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
            printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
            printf("\n\n");
        }
    }

    closedir(mydir);
}