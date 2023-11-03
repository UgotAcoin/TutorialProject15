#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <list>

#include "DialogueTree.h"

using namespace std;

int main()
{
	DialogueTree dialogueTree;

	dialogueTree.init();

	int rv = dialogueTree.performDialogue();

	if (rv == 1) {
		cout << "\nYou accepted the quest!\n";
	}

	dialogueTree.destroyTree();

	printf("\nPress any key to quit....\n");
	_getch();
	return 0;
}