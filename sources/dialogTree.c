#include "../headers/dialogTree.h"

dialogTree defaultDialogTree = {
	.dialog[0]='\0',
	.parent = 0,
	.numResponses = 0,
	.responses = 0,
	.nextDialog = 0
};

// initializes a dialogTree
void dialogTree_init(dialogTree** t){
	*t = INIT_DIALOGTREE();
	**t = defaultDialogTree;
}

void dialogTree_setDialog(dialogTree** t, char* d){
	dialogTree* temp = INIT_DIALOGTREE();
	*temp = **t;

	strcpy((*t)->dialog, d);

	(*t)->parent = temp->parent;
	(*t)->numResponses = temp->numResponses;
	//(*t)->responses = temp->responses;
	//(*t)->nextDialog = temp->nextDialog;
}
// add a new node to the dialog tree
void dialogTree_NewNode(dialogTree* t, char* d, char** r, size_t responseNum){
	dialogTree* child;
	dialogTree_init(&child);

    // add dialog and parent node
    strcpy(child->dialog, d);
    child->parent = t;

    // add responses
    int i = 0;
    while(r != 0 && r[i] != NULL){
        child->responses[i] = r[i];
		child->numResponses ++;
        i ++;
    }

    // add next dialog for after responses
    if(responseNum >= 0 && responseNum < NUM_RESPONSES)
		t->nextDialog[responseNum] = child;
}

// prints the dialog of the specified node in the dialog tree
void dialogTree_PrintDialog(dialogTree* t){
	printf("%s\n", t->dialog);

	if(t->numResponses != 0)
		for(int i = 0; i < t->numResponses; i ++)
			if(t->responses[i] != NULL)
				printf("%d. %s\n", i, t->responses[i]);
}
