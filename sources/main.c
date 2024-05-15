#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/fileHandler.h"
#include "../headers/dialogTree.h"

int main(int argc, char *argv[]){
	int lineOffset = 2;
    int numLines = 5;

	char **inputDialog = readFileLines("./txt/test.txt", lineOffset, numLines);

	for(int i = 0; i < numLines; i ++){
		printf("%s\n", inputDialog[i]);
	}

    return 0;
}
