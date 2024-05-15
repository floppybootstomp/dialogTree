#ifndef DIALOGTREE_H
#define DIALOGTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_RESPONSES 2
#define MAX_DIALOG_SIZE 50
#define INIT_DIALOGTREE() ((dialogTree*)(malloc(sizeof(dialogTree))))

// tree to hold the dialog strings, branches are responses, contains pointer to parent
typedef struct dialogTree {
    char dialog[MAX_DIALOG_SIZE];

    struct dialogTree* parent;
	int numResponses;
	char* responses[NUM_RESPONSES];
    struct dialogTree* nextDialog[NUM_RESPONSES];
}dialogTree;

// initializes a dialogTree
void dialogTree_init(dialogTree **t);

// sets dialog for a dialogTree
void dialogTree_setDialog(dialogTree** t, char* d);

// add a new node to the dialog tree
void dialogTree_NewNode(dialogTree* t, char* d, char** r, size_t responseNum);

// prints the dialog of the specified node in the dialog tree
void dialogTree_PrintDialog(dialogTree* t);

#endif // DIALOGTREE_H
