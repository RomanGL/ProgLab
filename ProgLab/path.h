#include <stdbool.h>

char *winToCygwin(char path[]);
bool checkPath(char path[], bool isLinux);
int getPathType(char path[]);