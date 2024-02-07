#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "parsing.h"
#include "macros.h"
void size_malloc(char *line, int *num_tokens) {
	char *token;
	char dilimiters []= " ";
	token = strtok(line, dilimiters);
	while (token != NULL) {
		(*num_tokens)++;
		// to get number of tokens to re-use in malloc
		token = strtok(NULL, " ");
	}

}

char** parsing(char *line, int num_tokens) {
	char **tokens = NULL;
	char *token;
	char dilimiters []= " ";
	// malloc tokens with num_tokens number +1 for NULL
	tokens = (char**) malloc((num_tokens + 1) * sizeof(char*));
	if (tokens == NULL) {
		//handling malloc failure
		printf("MALLOC Failed\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	token = strtok(line,dilimiters);
	//tokenize the string
	while (token != NULL) {
		tokens[i] = strdup(token);
		// strdup returns a pointer malloc duplicated string
		if (tokens == NULL) {
			//handling malloc failure
			printf("MALLOC Failed\n");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " ");
		// to get next token
	}
	tokens[num_tokens] = NULL;
	//putting last element as NULL pointer
	return tokens;

}


