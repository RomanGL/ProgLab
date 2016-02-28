#include <stdio.h>
#include "strings.h"

int slen(char string[])
{
	int i = 0;
	while (string[i] != '\0') i++;

	return i;
}

char *stok(char string[], char delim, int *position)
{
	int i = *position;
	char *str = &string[i];
	*position += 1;

	if (*str == '\0') return 0L;
	return str;
}