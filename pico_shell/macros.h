#ifndef MACROS_H_
#define MACROS_H_

#define ECHO 0
#define PWD 1
#define CD 2
#define EXIT 3
#define COMMAND 0
#define ARGUMENT1 1
#define ARGUMENT2 2
#define ARGUMENT3 3
#define IDENTICAL 0
#define EXIT_SUCCESS 0
#define  disable_buffering();{\
      	setvbuf(stdout, NULL, _IONBF, 0);\
	 setvbuf(stderr, NULL, _IONBF, 0);\
}
#endif
