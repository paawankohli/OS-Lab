#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void main() {
    char path[50];
    printf("Enter path: ");
    scanf("%s", path);

    DIR* fd = opendir(path);
    struct stat buff;

    struct dirent* entry;

    while ((entry = readdir(fd)) != NULL) {
        stat(entry->d_name, &buff);

        printf("Name: %s\n\n", entry->d_name);

        if (!S_ISDIR(buff.st_mode)) {
            printf("Device Node: %ld\n", buff.st_dev);
            printf("Inode Number: %ld\n", buff.st_ino);
            printf("Mode Bytes: %d\n", buff.st_mode);
            printf("Number of Hard Links: %ld\n", buff.st_nlink);

            printf("Owner User ID: %d\n", buff.st_uid);
            printf("Owner Group ID: %d\n", buff.st_gid);
            printf("File Size: %ld bytes\n", buff.st_size);
            printf("Preffered Block Size: %ld bytes\n", buff.st_blksize);
            printf("Number of Filesystem Blocks: %ld\n", buff.st_blocks);

            printf("Last Access Time: %s", ctime(&buff.st_atime));
            printf("Last Modification Time: %s", ctime(&buff.st_mtime));
            printf("Last Change Time: %s", ctime(&buff.st_mtime));
        }
    }
}

