// Simulate ls -l

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void main(int agrc, char ** argv) {
    
    DIR *mydir = opendir(argv[1]);
    struct stat fileStat;
    struct dirent* myfile;

    while ((myfile = readdir(mydir)) != NULL) {
        stat(myfile->d_name, &fileStat);

        if (strcmp(".", myfile->d_name) == 0 || strcmp("..", myfile->d_name) == 0) {
            continue;
        }
        else {
            printf("Filename: %s\n", myfile->d_name);
            printf("Permission: ");

            printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
            
            printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");

            printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
            printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");

            printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
            printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
            printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

            printf("\n\n");
        }
    }

    closedir(mydir);
}