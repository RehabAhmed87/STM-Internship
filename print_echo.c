#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
void echo (char *sentence);
int main ()
{
	int flag=1;
	char sen[MAX_SENTENCE_LENGTH];
	do
	{
	 printf("Type to echo : \n");
	fgets(sen,MAX_SENTENCE_LENGTH,stdin);

	if ((strncmp(sen,"exit",4)==0))
	{
	printf("Good bye.\n");
	flag=0;
	}
	else
	{
	echo(sen);
	}

	}while (flag);
}
void echo (char *sentence)
{
        printf("You said :%s \n", sentence);

}

