#include <stdio.h>
#include <stdbool.h>
#include "path.h"
#include "strings.h"

#define MAX_PATH 260

const char CYGWIN_ROOT[] = "/cygdrive/";
const int CYGWIN_LENGTH = 10;

bool checkPath(char path[], bool isLinux);
int getPathType(char path[]);

char *winToCygwin(char path[])
{
	int pathType = getPathType(path);
	if (pathType == 0)
	{
		if (stringLength(path) >= 249)
		{
			printf("Error: can't convert to Cygwin. Max length of Linux path exceeded.\n");
			return NULL;
		}

		char *cygwinPath = malloc(sizeof(char) * (MAX_PATH + 1));
		if (cygwinPath == NULL)
		{
			printf("Error: no enough memory (winToCygwin)! Skiping path.\n");
			return NULL;
		}

		cygwinPath[0] = '\0';

		stringConcat(cygwinPath, CYGWIN_ROOT);
		cygwinPath[CYGWIN_LENGTH] = toLowerCase(path[0]);
		cygwinPath[CYGWIN_LENGTH + 1] = '\0';

		stringReplace(&path[2], '\\', '/');
		stringConcat(cygwinPath, &path[2]);

		return cygwinPath;
	}
	else if (pathType == 1)
		return path;
	
	return NULL;
}

bool checkPath(char path[], bool isLinux)
{
	bool noErrors = true;

	if (stringLength(path) > MAX_PATH)
	{
		printf("Error: max length of path exceeded.\n");
		noErrors = false;
	}
		
	int i = 0;
	while (path[i] != '\0')
	{
		switch (path[i])
		{
			case '*':
			case '?':
			case '"':
			case '<':
			case '>':
			case '|':
			case ':':
				printf("Error: unsupported symbol '%c' in %d position.\n", path[i], i + 1);
				noErrors = false;
				break;
		}

		if (isLinux)
		{
			if (path[i] == '\\')
			{
				printf("Error: unsupported symbol '%c' in %d position.\n", path[i], i + 1);
				noErrors = false;
			}
		}
		else
		{
			if (path[i] == '/')
			{
				printf("Error: unsupported symbol '%c' in %d position.\n", path[i], i + 1);
				noErrors = false;
			}
		}

		i++;
	}

	return noErrors;
}

int getPathType(char path[])
{
	if (path[0] == '/')
	{
		if (checkPath(path, true))
			return 1;
		else
			printf("Error: can't convert to Cygwin. Invalid Linux path.\n");
	}
	else if (path[1] == ':')
	{
		if (isLetter(path[0]) && path[2] == '\\')
		{
			if (checkPath(&path[2], false))
				return 0;
		}

		printf("Error: can't convert to Cygwin. Invalid Windows path.\n");
	}
	else
		printf("Error: can't convert to Cygwin. Invalid path.\n");

	return -1;
}