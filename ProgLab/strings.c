#include <stdio.h>
#include "strings.h"

int stringLength(char string[])
{
	int i = 0;
	while (string[i] != '\0') 
		i++;

	return i;
}

char *stringToken(char string[], char delim)
{
	static char *splitString;

	if (string != NULL) 
		splitString = string;

	if (splitString == NULL)
		return NULL;

	return NULL;
}

int stringIndexOf(char string[], char symbol)
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == symbol) 
			return i;

		i++;
	}

	return -1;
}

void stringConcat(char destStr[], char sourceStr[])
{
	int destLen = stringLength(destStr);
	int sIndex = 0;

	while (sourceStr[sIndex] != '\0')
	{
		destStr[destLen + sIndex] = sourceStr[sIndex];
		sIndex++;
	}

	destStr[destLen + sIndex] = '\0';
}

void stringCopy(char destStr[], char sourceStr[])
{
	int i = 0;
	while (sourceStr[i] != '\0')
	{
		destStr[i] = sourceStr[i];
		i++;
	}

	destStr[i] = '\0';
}