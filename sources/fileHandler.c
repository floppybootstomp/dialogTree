#include "../headers/fileHandler.h"
#include "../headers/macros.h"

// return a string with the contents of a file
char* readFile(char* filename){
    char* fileContents;
    size_t fileSize;
    size_t readSize;

    // open file
    FILE* f = fopen(filename, "r");
    if(f == NULL){
        fputs("failed to read file", stderr);
        exit(1);
    }

    // find the file size
    fseek(f, 0, SEEK_END);
    fileSize = ftell(f);
    rewind(f);

    // allocate memory for file contents
    fileContents = (char*)(malloc(fileSize * sizeof(char)));
    if(fileContents == NULL){
        fputs("failed to allocate memory for file contents", stderr);
        exit(1);
    }

    // read file contents
    readSize = fread(fileContents, 1, fileSize, f);
    if(readSize != fileSize){
        fputs("failed to read file contents", stderr);
        exit(1);
    }

    fclose(f);

    return fileContents;
}

char** readFileLines(char* filename, int offset, int numLines){
	char** fileContents;
	char readBuffer;
	size_t readSize;

    // open file
    FILE* f = fopen(filename, "r");
    if(f == NULL){
        fputs("failed to read file", stderr);
        exit(1);
    }

    // allocate memory for file contents
    fileContents = (char**)(malloc(numLines * sizeof(char*)));

	for(int i = 0; i < numLines; i ++)
        fileContents[i] = (char*)(malloc(MAX_DIALOGLENGTH * sizeof(char)));

    if(fileContents == NULL){
        fputs("failed to allocate memory for file contents", stderr);
        exit(1);
    }

	// find start position
	for(int startPosition; startPosition < offset; startPosition ++)
		fgets(fileContents[0], MAX_DIALOGLENGTH, f);

    // read file contents
	int lineCount = 0;
	int i = 0;
	while(lineCount < numLines && i < MAX_DIALOGLENGTH - 1 && readBuffer != EOF){
		readBuffer = getc(f);

		if(readBuffer == '\n'){
			fileContents[lineCount][i] = '\0';
			i = 0;
			lineCount ++;
		}
		else{
			fileContents[lineCount][i] = readBuffer;
			i ++;
		}
	}

    fclose(f);

    return fileContents;
}
