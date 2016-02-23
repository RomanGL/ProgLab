#include <stdio.h>

#define MAX_PATH 260

void input(char str[]);
bool check(char str[]);
void process();
void output();

int main()
{
	char str[MAX_PATH];
	input(str);
	bool res = check(str);
}

void input(char str[])
{
	printf("Input path:\n");
	fgets(str, MAX_PATH, stdin);
}

bool check(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
			case '*':
			case '?':
			case '"':
			case '<':
			case '>':
			case '|':
				return false;
		}
	}
	return true;
}

void process()
{
}

void output()
{
}
