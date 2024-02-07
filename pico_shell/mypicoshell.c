#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "built-in_functions.h"
#include "macros.h"
#include "parsing.h"
extern char **environ;
int main() {
	//macros to disable buffering
	disable_buffering();
	printf("Welcome to pico shell please enter: command argument(s) \n");
	printf("For exit just type exit \n");
	while (1) {
		// here i make two lines one to find number of tokens
		// the other to parse the line
		char *line = NULL;
		char *linedup = NULL;
		//getline will allocate line with size of line it gets
		// if buffer_size was 0 it will allocate line with size
		// if buffer_size was less that line size it will resize it with realloc
		//since it's dynamic memory allocation line must be freed here it free it at the end of program
		size_t buffer_size = 0;
		ssize_t input_size = getline(&line, &buffer_size, stdin);
		// if getline failed to allocate it will return -1
		if (input_size == -1) {
			printf("Failed to getline\n");
			exit(EXIT_FAILURE); /**< Exit if getline fails */
		}
		//clearing line from enter char occurence
		if (strcmp(line, "\n") == 0) {
			continue;
		}
		int enter_occurence = strcspn(line, "\n");
		line[enter_occurence] = '\0';

		// duplicate line to use one to know number of tokens and other one for parsing
		linedup = strdup(line);
		int num_tokens = 0;
		//getting number of tokens
		size_malloc(linedup, &num_tokens);
		// parsing the token
		char **tokens = parsing(line, num_tokens);
		// array of command strings for built-in commands
		char *commands[] = { "echo", "pwd", "cd", "exit" };
		// check if command was a built-in command
		if (strcmp(commands[ECHO], tokens[COMMAND]) == IDENTICAL) {
			echo(tokens);
		} else if (strcmp(commands[PWD], tokens[COMMAND]) == IDENTICAL) {
			pwd();
		} else if (strcmp(commands[CD], tokens[COMMAND]) == IDENTICAL) {
			cd(tokens, num_tokens);
		} else if (strcmp(commands[EXIT], tokens[COMMAND]) == IDENTICAL) {
		exitt();
		} else {
			// if it wasn't a built in command
			pid_t returned_pid = fork();
			if (returned_pid > 0) {
				// if pid >0 then i got a child so i will wait for it until it's executed and terminated
				int wstatus;
				wait(&wstatus);
			} else if (returned_pid == 0) {
				// here execvpe only needs name of command not file path
				execvpe(tokens[0], tokens, environ);

				printf("exeute failure please check command name\n");
				// if exec failed so there is a problem in command name probably
				exit(0);
				//terminats child as exec failed
			} else {
				// in case of 0 then fork has failed
				printf("Failed to execute command\n");
			}
		}

		//free tokens to avoid memory leak
		for (int i = 0; i < num_tokens; i++) {
			free(tokens[i]);
		}
		free(tokens);
		//free lines to avoid memory leak
		free(line);
		free(linedup);
	}
}
