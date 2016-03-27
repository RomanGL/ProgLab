#include <stdbool.h>

// ���������� ����� ������.
int stringLength(char string[]);

// ������� ������� ������.
void stringRemoveNewLine(char string[]);

// ���������� ��������� �� ������ �����, ����������� ������������.
// �������� ������ ��� ������ ������ � NULL ��� ����������� ��� ������� ������.
char *stringToken(char string[], char delim);

// ��������������� ������ ����� stringToken.
void stringRestoreToken(char string[], int count, char delim);

// ���������� ������ ������� ��������� ���������� ������� � ������ ��� -1 � ��������� ������.
int stringIndexOf(char string[], char symbol);

// ��������� ��� ������ � destStr (������ ����� ����� destStr + sourceStr + 1).
void stringConcat(char destStr[], char sourceStr[]);

// �������� sourceStr � destStr (������ ����� ����� sourceString + 1).
void stringCopy(char destStr[], char sourceStr[]);

// �������� ��� ��������� ������� symbol �� replaceTo � ��������� ������.
void stringReplace(char string[], char symbol, char replaceTo);

// �������� ������ � ������� ��������.
char toLowerCase(char symbol);

// �������� ������ � �������� ��������.
char toUpperCase(char symbol);

// �������� �� ������ ������.
bool isLetter(char symbol);

// ���������� true, ���� ������ ������ ��������� � token, ����� false.
bool stringStartWith(char string[], char token[], bool ignoreCase);

// ���������� true ���� ����� ������ ��������� � token, ����� false.
bool stringEndWith(char string[], char token[], bool ignoreCase);