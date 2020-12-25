// metadata - stat

#include <sys/types.h>
#include <sys/stat.h> // imp
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

/*
int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);

all 3 return 0 if succesful and store info about file in pointer

stat is used to return info about denoted by a path
fstat is used to return info about a file denoted by file descriptor
lstat is used for paths too BUT in case of a symbolic link, lstat()

*/

/*

struct stat {
	dev_t		st_dev;		ID of device containing file
	ino_t		st_ino;		Inode number
	mode_t		st_mode;	File type and mode/permissions
	nlink_t		st_nlink;	Number of hard links
	uid_t		st_uid;		User ID of owner
	gid_t		st_gid;		Group ID of owner
	dev_t		st_rdev;	Device ID (if special file)
	off_t		st_size;	Total size, in bytes
	blksize_t	st_blksize;	Block size for filesystem I/O
	blkcnt_t	st_blocks;	Number of 512B blocks allocated

	time_t 		st_atime;	Time of last access
	time_t		st_mtime;	Time of last modification
	time_t		st_ctime;	Time of last status change
};

*/