#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_RESPONSES 2
#define MAX_DIALOG_SIZE 50
#define INIT_DIALOGTREE() ((struct dialogTree*)(malloc(sizeof(struct dialogTree))))

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

// tree to hold the dialog strings, branches are responses, contains pointer to parent
struct dialogTree{
    char dialog[MAX_DIALOG_SIZE];

    struct dialogTree* parent;
    struct dialogTree* responses[NUM_RESPONSES];
};

// add a new node to the dialog tree
void dialogTree_NewNode(struct dialogTree* t, char* d, int responseNum){
    struct dialogTree* child = INIT_DIALOGTREE();

    strcpy(child->dialog, d);
    child->parent = t;

    if(responseNum >= 0 && responseNum < NUM_RESPONSES)
	t->responses[responseNum] = child;
}

// prints the dialog of the specified node in the dialog tree
void dialogTree_PrintDialog(struct dialogTree* t){
    printf("%s\n", t->dialog);

    for(int i = 0; i < NUM_RESPONSES; i ++)
	if(t->responses[i] != NULL)
	    printf("%d. %s\n", i, t->responses[i]->dialog);
}

int main(int argc, char *argv[]){
    struct dialogTree* n = INIT_DIALOGTREE();

    char* inputDialog = readFile("./txt/test.txt");

    strcpy(n->dialog, inputDialog);

    dialogTree_PrintDialog(n);

    return 0;
}
