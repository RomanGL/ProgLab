#include <stdio.h>
#include <stdbool.h>

bool fileWriteAllText(char filePath[], char text[]);
bool fileWriteLine(char filePath[], char line[]);
bool fileWriteSymbol(char filePath[], char symbol);

char *fileReadAllText(char filePath[]);
char *fileReadLine(char filePath[]);
char fileReadSymbol(char filePath[]);

void fileTryClose(FILE *stream);
