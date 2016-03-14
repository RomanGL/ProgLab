#include <stdio.h>
#include "strings.h"

// Возвращает длину строки.
int stringLength(char string[])
{
	int i = 0;
	while (string[i] != '\0')
		i++;

	return i;
}

// Возвращает указатель на начало блока, отделенного разделителем.
// Передать строку при первом вызове и NULL при последующих для текущей строки.
char *stringToken(char string[], char delim)
{
	static char *splitString;
	char *token;

	if (string != NULL)
		splitString = string;

	if (splitString == NULL)
		return NULL;

	int i = 0;
	while (*(splitString + i) != '\0')
	{
		if (*(splitString + i) == delim)
		{
			token = splitString;
			*(splitString += i) = '\0';
			splitString += 1;

			return token;
		}
		i++;
	}

	token = splitString;
	splitString = NULL;
	return token;
}

// Восстанавливает строку после stringToken.
void stringRestoreToken(char string[], int count, char delim)
{
	int i = 0;
	while (count > 0)
	{
		if (string[i] == '\0')
		{
			string[i] = delim;
			count--;
		}

		i++;
	}
}

// Возвращает индекс первого вхождения указанного символа в строку или -1 в противном случае.
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

// Склеивает две строки в destStr (должен иметь длину destStr + sourceStr + 1).
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

// Копирует sourceStr в destStr (должен иметь длину sourceString + 1).
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

// Возвращает true, если начало строки совпадает с token, иначе false.
bool stringStartWith(char string[], char token[])
{
	int tokenLength = stringLength(token);
	for (int i = 0; i < tokenLength; i++)
	{
		if (string[i] == '\0')
			return false;
		if (string[i] != token[i])
			return false;
	}

	return true;
}

// Возвращает true если конец строки совпадает с token, иначе false.
bool stringEndWith(char string[], char token[])
{
	int strLength = stringLength(string) - 1;
	int tokenLength = stringLength(token) - 1;

	if (tokenLength > strLength)
		return false;

	while (tokenLength >= 0)
	{
		if (string[strLength] != token[tokenLength])
			return false;

		strLength--;
		tokenLength--;
	}

	return true;
}