#include <stdbool.h>

// Возвращает длину строки.
int stringLength(char string[]);

// Возвращает указатель на начало блока, отделенного разделителем.
// Передать строку при первом вызове и NULL при последующих для текущей строки.
char *stringToken(char string[], char delim);

// Возвращает индекс первого вхождения указанного символа в строку или -1 в противном случае.
int stringIndexOf(char string[], char symbol);

// Склеивает две строки в destStr (должен иметь длину destStr + sourceStr + 1).
void stringConcat(char destStr[], char sourceStr[]);

// Копирует sourceStr в destStr (должен иметь длину sourceString + 1).
void stringCopy(char destStr[], char sourceStr[]);

// Возвращает true, если начало строки совпадает с token, иначе false.
bool stringStartWith(char string[], char token[]);

// Возвращает true если конец строки совпадает с token, иначе false.
bool stringEndWith(char string[], char token[]);