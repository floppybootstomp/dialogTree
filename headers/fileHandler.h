#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <stdlib.h>

// return a string with the contents of a file
char* readFile(char* filename);

char** readFileLines(char* filename, int offset, int numLines);

#endif // FILEHANDLER_H
