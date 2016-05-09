#include <stdio.h>
#include "strings.h"

// ���������� ����� ������.
int stringLength(char string[])
{
	int i = 0;
	while (string[i] != '\0')
		i++;

	return i;
}

// ������� ������� ������.
void stringRemoveNewLine(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			string[i] = '\0';

		i++;
	}
}

// ���������� ��������� �� ������ �����, ����������� ������������.
// �������� ������ ��� ������ ������ � NULL ��� ����������� ��� ������� ������.
char *stringToken(char string[], char delim[])
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
		int j = 0;
		while (delim[j] != '\0')
		{
			if (*(splitString + i) == delim[j])
			{
				token = splitString;
				*(splitString += i) = '\0';
				splitString += 1;

				return token;
			}
			j++;
		}

		i++;
	}

	token = splitString;
	splitString = NULL;
	return token;
}

// ��������������� ������ ����� stringToken.
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

// ���������� ������ ������� ��������� ���������� ������� � ������ ��� -1 � ��������� ������.
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

// ��������� ��� ������ � destStr (������ ����� ����� destStr + sourceStr + 1).
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

// �������� sourceStr � destStr (������ ����� ����� sourceString + 1).
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

// �������� ��� ��������� ������� symbol �� replaceTo � ��������� ������.
void stringReplace(char string[], char symbol, char replaceTo)
{
	if (symbol == '\0' || replaceTo == '\0')
		return;

	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == symbol)
			string[i] = replaceTo;
		i++;
	}
}

// �������� ������ � ������� ��������.
char toLowerCase(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
		return symbol + ('a' - 'A');
	return symbol;
}

// �������� ������ � �������� ��������.
char toUpperCase(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
		return symbol - ('a' - 'A');
	return symbol;
}

// �������� �� ������ ������.
bool isLetter(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
		return true;
	if (symbol >= 'a' && symbol <= 'z')
		return true;

	return false;
}

// ���������� true, ���� ������ ������ ��������� � token, ����� false.
bool stringStartWith(char string[], char token[], bool ignoreCase)
{
	int tokenLength = stringLength(token);
	for (int i = 0; i < tokenLength; i++)
	{
		if (string[i] == '\0')
			return false;

		if (ignoreCase && toLowerCase(string[i]) != toLowerCase(token[i]))
			return false;
		else if (string[i] != token[i])
			return false;
	}

	return true;
}

// ���������� true ���� ����� ������ ��������� � token, ����� false.
bool stringEndWith(char string[], char token[], bool ignoreCase)
{
	int strLength = stringLength(string) - 1;
	int tokenLength = stringLength(token) - 1;

	if (tokenLength > strLength)
		return false;

	while (tokenLength >= 0)
	{
		if (ignoreCase && toLowerCase(string[strLength]) != toLowerCase(token[tokenLength]))
			return false;
		else if (string[strLength] != token[tokenLength])
			return false;

		strLength--;
		tokenLength--;
	}

	return true;
}