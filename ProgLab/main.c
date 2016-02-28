#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "strings.h"

#define MAX_PATH 261
#define MAX_COUNT 10

void input(char string[], char *delim);
bool check(char string[]);
void process(char string[], char delim);
void output(char string[]);

int main()
{
	char delim;
	char str[MAX_PATH * MAX_COUNT];
	input(str, &delim);

	bool checkResult = check(&str);
	if (!checkResult)
	{
		printf("Error: unsupported symbol");
		_getch();
		exit();
	}

	process(str, delim);

	_getch();
}

void input(char string[], char *delim)
{
	printf("Input delim: ");
	scanf_s("%c%*c", delim);

	printf("Input path:\n");
	fgets(string, MAX_PATH * MAX_COUNT, stdin);
}

bool check(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n') string[i] = '\0';
		else
		{
			switch (string[i])
			{
				case '*':
				case '?':
				case '"':
				case '<':
				case '>':
				case '|':
					return false;
			}

			i++;
		}
	}

	return true;
}

void process(char string[], char delim)
{
	int position = 0;
	char *part = stok(string, delim, &position);

	while (part != NULL)
	{
		output(part);
		part = stok(string, delim, &position);
	}
}

void output(char string[])
{
	printf("%s\n", string);
}
