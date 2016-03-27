#include <stdbool.h>

// Возвращает длину строки.
int stringLength(char string[]);

// Удаляет перенос строки.
void stringRemoveNewLine(char string[]);

// Возвращает указатель на начало блока, отделенного разделителем.
// Передать строку при первом вызове и NULL при последующих для текущей строки.
char *stringToken(char string[], char delim);

// Восстанавливает строку после stringToken.
void stringRestoreToken(char string[], int count, char delim);

// Возвращает индекс первого вхождения указанного символа в строку или -1 в противном случае.
int stringIndexOf(char string[], char symbol);

// Склеивает две строки в destStr (должен иметь длину destStr + sourceStr + 1).
void stringConcat(char destStr[], char sourceStr[]);

// Копирует sourceStr в destStr (должен иметь длину sourceString + 1).
void stringCopy(char destStr[], char sourceStr[]);

// Заменяет все вхождения символа symbol на replaceTo в указанной строке.
void stringReplace(char string[], char symbol, char replaceTo);

// Приводит символ к нижнему регистру.
char toLowerCase(char symbol);

// Приводит символ к верхнему регистру.
char toUpperCase(char symbol);

// Является ли символ буквой.
bool isLetter(char symbol);

// Возвращает true, если начало строки совпадает с token, иначе false.
bool stringStartWith(char string[], char token[], bool ignoreCase);

// Возвращает true если конец строки совпадает с token, иначе false.
bool stringEndWith(char string[], char token[], bool ignoreCase);