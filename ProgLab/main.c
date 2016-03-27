#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "strings.h"
#include "path.h"

#define MAX_PATH 260
#define MAX_COUNT 10

void input(char string[], char *delim);
void process(char string[], char delim);
void output(char string[]);

int main()
{
	char delim;
	char str[MAX_PATH * MAX_COUNT + 10];

	input(str, &delim);
	process(str, delim);

	_getch();
	return 0;
}

void input(char string[], char *delim)
{
	printf("Input delimiter: ");
	scanf_s("%c%*c", delim);

	printf("Input path: ");
	fgets(string, (MAX_PATH * MAX_COUNT) + 9, stdin);
	stringRemoveNewLine(string);
}

void process(char string[], char delim)
{
	int skipped = 0;
	int success = 0;

	char *resultCygwin = malloc(sizeof(char) * (MAX_PATH * MAX_COUNT + 10));
	if (resultCygwin == NULL)
	{
		printf("\nError: no enought memory (process)! Can't continue.\n");
		return;
	}

	resultCygwin[0] = '\0';
	char strDelim[2] = { delim };

	char *token = stringToken(string, delim);
	while (token != NULL)
	{	
		printf("\nProcessing path: %s\n", token);

		char *cygwin = winToCygwin(token);
		if (cygwin != NULL)
		{
			if (success != 0)
			{
				stringConcat(resultCygwin, strDelim);
				stringConcat(resultCygwin, cygwin);
			}
			else
				stringConcat(resultCygwin, cygwin);

			success++;
			printf("Success\n");
		}
		else
		{
			printf("Path skipped.\n");
			skipped++;
		}

		token = stringToken(NULL, delim);		
	}

	if (skipped > 0)
		printf("\nNotice! %d paths was skipped due to an error. %d path success.\n", 
			skipped, success);

	printf("\n**********\n%s\n", resultCygwin);
}

void output(char string[])
{
	printf("%s\n", string);
}
