#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
	printf
	    ("wrong usage type  ./myecho \"sentence\" or ./myecho sentence\n");
	//if i wrote sentence in double quotes it will be taken as one argument
	// if i wrote it without double quotes it will be multiple arguments that i should loop for printing each one 
	return -1;
    } else if (argc == 2) {
	printf("echo : %s\n", argv[1]);
	return 0;
    } else {
	printf("echo : ");
	for (int i = 1; i < argc; i++) {
	    // looping from 1 to argc as argv[0] is function name
	    // argv[argc] = NULL
	    printf("%s ", argv[i]);
	}
	printf("\n");
    }
}
