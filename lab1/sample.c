#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

// stdin 	0
// stdout 	1
// stderr	2

void main() {

	// read system call:
	// size_t read(int fildes, void *buf, size_t nbytes);
	// read nbytes of data from flides and store in buf


	// write system call:
	// size_t write(int fildes, const void *buf, size_t nbytes);
	// write nbytes of data from buf to fildes


	// open system call
	// int open(const char *path, int oflags);
	// int open(const char *path, int oflags, mode_t mode);
	// returns a file descriptor that can be used in other system calls

	// oflags:
	// O_RDONLY 	Open for read only
	// O_WRONLY 	Open for write only
	// O_RDWR 		Open for reading and writing

	// O_APPEND 	Place written data at the end of the file.
	// O_TRUNC 		Set the length of the file to zero, discarding existing contents.
	// O_CREAT		Creates the file (if necessary) with permissions given in mode.

	// Give permission in mode. Use bitwise OR
	// S_IRUSR : Read permission, owner
	// S_IWUSR : Write permission, owner
	// S_IXUSR : Execute permission, owner
	// S_IRGRP : Read permission, group
	// S_IWGRP : Write permission, group
	// S_IXGRP : Execute permission, group
	// S_IROTH : Read permission, others
	// S_IWOTH : Write permission, others
	// S_IXOTH : Execute permission, others


	// close sytem call
	// int close(int fildes);
	// terminate the association between a file descriptor and its file

	// program using above sytem calls:

	char buffer[1024];
	int in = open("in.txt", O_RDONLY);
	int out = open("out.txt", O_WRONLY | O_CREAT, 0777);

	int nread;
	
	while ((nread = read(in, buffer, sizeof(buffer))) > 0) {
		write(out, buffer, nread);
	}

	close(in);
	close(out);
}