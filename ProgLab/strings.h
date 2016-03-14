#include <stdbool.h>

// ���������� ����� ������.
int stringLength(char string[]);

// ���������� ��������� �� ������ �����, ����������� ������������.
// �������� ������ ��� ������ ������ � NULL ��� ����������� ��� ������� ������.
char *stringToken(char string[], char delim);

// ���������� ������ ������� ��������� ���������� ������� � ������ ��� -1 � ��������� ������.
int stringIndexOf(char string[], char symbol);

// ��������� ��� ������ � destStr (������ ����� ����� destStr + sourceStr + 1).
void stringConcat(char destStr[], char sourceStr[]);

// �������� sourceStr � destStr (������ ����� ����� sourceString + 1).
void stringCopy(char destStr[], char sourceStr[]);

// ���������� true, ���� ������ ������ ��������� � token, ����� false.
bool stringStartWith(char string[], char token[]);

// ���������� true ���� ����� ������ ��������� � token, ����� false.
bool stringEndWith(char string[], char token[]);