#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include "../ProgLab/strings.h"
#include "io.h"

#define BUFFER_SIZE 8192

bool fileWriteAllText(char filePath[], char text[])
{
	return false;
}

bool fileWriteLine(char filePath[], char line[])
{
	return false;
}

bool fileWriteSymbol(char filePath[], char symbol)
{
	return false;
}

char *fileReadAllText(char filePath[])
{
	FILE *stream = fopen(filePath, "r");
	if (stream == NULL)
	{
		printf("Error: Can't open the file \"%s\"!\n", filePath);
		return NULL;
	}

	fseek(stream, 0, SEEK_END);
	long size = ftell(stream);

	char *result = malloc(size + 1);
	if (result == NULL)
	{
		fclose(stream);
		printf("Error: no enough memory (fileReadAllText)!\n");
		return NULL;
	}

	fseek(stream, 0, SEEK_SET);

	int position = 0;
	while (fgets(&(result[position]), size, stream) != NULL)
	{
		position += stringLength(&(result[position]));
	}

	fclose(stream);
	return result;
}

char *fileReadLine(char filePath[])
{
	static FILE *stream;

	if (filePath != NULL)
	{
		fileTryClose(stream);
		stream = fopen(filePath, "r");
	}

	if (stream == NULL)
	{
		printf("Error: Can't open the file \"%s\"!\n", filePath);
		return NULL;
	}

	char *result = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (result == NULL)
	{
		fclose(stream);
		printf("Error: no enough memory (fileReadAllText)!\n");
		return NULL;
	}

	if (fgets(result, BUFFER_SIZE, stream) == NULL)
	{
		free(result);
		return NULL;
	}

	return result;
}

char fileReadSymbol(char filePath[])
{
	return 0;
}

void fileTryClose(FILE *stream)
{
	if (stream != NULL)
		fclose(stream);
}
