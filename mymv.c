#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX_SIZE_BUFFER 100
#define READ_OPEN_FAILED -1
#define READ_FAILED -2
#define WRITE_OPEN_FAILED -3
#define WRITE_FAILED -4
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int read_file(char *file_path, char *read_buffer, int buffer_size)
{
    static int fd_read;
    int num_bytes_read;
    fd_read = open(file_path, O_RDONLY);
    //int open(const char *pathname, mode_t mode);
    if (fd_read < 0) {
	//if failed to open
	return READ_OPEN_FAILED;
    }
    num_bytes_read = read(fd_read, read_buffer, buffer_size);
    if (num_bytes_read < 0) {
	//if failed to read
	close(fd_read);
	return READ_FAILED;
    } else if (num_bytes_read == 0) {
	close(fd_read);
	return num_bytes_read;
    } else {
	return num_bytes_read;
    }
}

int write_file(char *file_path, char *read_buffer, int buffer_size)
{
    static int fd_write;
    int num_bytes_write;
    fd_write = open(file_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd_write ==-1) {
	//if failed to open
	return WRITE_OPEN_FAILED;
    }

    num_bytes_write = write(fd_write, read_buffer, buffer_size);
    //ssize_t write(int fd, const void *buf, size_t count);
    if (num_bytes_write < 0) {
	//if failed to write
	close(fd_write);
	return WRITE_FAILED;
    } else if (num_bytes_write == 0) {
	close(fd_write);
	return num_bytes_write;
    } else {
	close(fd_write);
	return num_bytes_write;
    }
}

int main(int argc, char *argv[])
{
    char buffer[MAX_SIZE_BUFFER];
    int num_bytes_read, num_bytes_write;
    if (argc != 3) {
	printf("Usage %s file_name new_file_name \n", argv[0]);
	printf("OR\nUsage %s file_name path \n", argv[0]);
	return -1;
    }

    do {
	num_bytes_read = read_file(argv[1], buffer, sizeof(buffer));
	if (num_bytes_read < 0) {
	    break;
	}
	//int read_file (char *file_path, char *read_buffer , int buffer_size)
	num_bytes_write = write_file(argv[2], buffer, num_bytes_read);
	if (num_bytes_write < 0) {
	    break;
	}
	//int write_file (char  *file_path, char *read_buffer , int buffer_size)
    }
    while (num_bytes_read != 0);
    if (num_bytes_read == READ_OPEN_FAILED) {
	printf("read failed to open file\n");
    }
    if (num_bytes_read == READ_FAILED) {
	printf("read failed to read file\n");
    }
    if (num_bytes_write == WRITE_OPEN_FAILED) {
	printf("write failed to open file\n");
    }
    if (num_bytes_write == WRITE_FAILED) {
	printf("write failed to write file\n");
    }
     remove(argv[1]);
        return 0;
   
}
