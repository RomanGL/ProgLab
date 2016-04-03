#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
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

	int pathsCounter = 0;
	char *token = stringToken(string, delim);
	while (token != NULL)
	{	
		pathsCounter++;
		if (pathsCounter <= MAX_COUNT)
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

				free(cygwin);
				cygwin = NULL;

				success++;
				output("Success");
			}
			else
			{
				output("Path skipped.");
				skipped++;
			}
		}
		else
			skipped++;

		token = stringToken(NULL, delim);		
	}

	if (pathsCounter > MAX_COUNT)
		printf("\nError: max paths number exceeded.");

	if (skipped > 0)
		printf("\nNotice! %d paths was skipped due to an error. %d path success.", 
			skipped, success);

	printf("\n**********\n");
	output(resultCygwin);
}

void output(char string[])
{
	printf("%s\n", string);
}
