// PWD :  print name of current/working directory
// how can we make it from scratch, first we want to get the name of current working directory then we can easily print it.
// I will use  getcwd :get current working directory 
// prototype : char *getcwd(char *buf, size_t size); 
// how it works : The  getcwd()  function  copies an absolute pathname of the current working directory
//  to the array pointed to by buf, which is of length size.
//  If the length of the absolute pathname of the current working directory
//  including the  terminating null byte, exceeds size bytes, NULL is returned
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAX_BUF_SIZE 300

int main(int argc, int *argv[])
{

    char buf[MAX_BUF_SIZE];
    // buffer to store path name
    if (getcwd(buf, MAX_BUF_SIZE) == NULL) {
	// if NULL is returned ny getcwd then the buffer size needs to be extented
	printf
	    ("Path name to long, please change buffer size to work properly\n");
	printf("Current size %d \n", MAX_BUF_SIZE);
	return -1;
    } else {
	printf("I am in path :%s\n", buf);
	//prints the path properly
	return 0;
    }

}
