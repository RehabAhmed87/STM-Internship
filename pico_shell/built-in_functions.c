#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "built-in_functions.h"
#include "macros.h"

#define PWD_BUFFER_SIZE 1000
void echo(char *sentence[]) {

	int i = 1;
	// printfing tokens
	while (sentence[i] != NULL) {
		printf("%s ", sentence[i]);
		i++;
	}
	printf("\n");
}

void pwd() {
	char path[PWD_BUFFER_SIZE];
	// buffer to store path name
	if (getcwd(path, PWD_BUFFER_SIZE) == NULL) {
		// if NULL is returned ny getcwd then the buffer size needs to be extented
		printf(
				"Path name to long, please change buffer size to work properly\n");
		printf("Current size %d \n", PWD_BUFFER_SIZE);
	} else {
		printf("I am in path :%s\n", path);
		//prints the path properly
	}
}

void cd(char *file_path[], int num_tokens) {
	char path[PWD_BUFFER_SIZE];
	//int chdir(const char *path);
	//chdir() changes the current working
	//directory of the calling process to
	//the directory specified in path.
	// On success, zero is returned.
	//On error, -1 is returned
	if (num_tokens == 1) {
		printf("Usage : cd file_path\n");
	} else {
		if (chdir(file_path[1]) == 0) {
			// in case of chdir success it returns 0
			// print current working directory
			getcwd(path, PWD_BUFFER_SIZE);
			printf("I am in path :%s\n", path);
		} else {
			printf("ERROR couldn't CD\n");
		}
	}
}
void exitt() {
	printf("Good Bye :)\n");
	exit(EXIT_SUCCESS);
}
