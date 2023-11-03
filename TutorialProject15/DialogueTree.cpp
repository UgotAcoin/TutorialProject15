#include "DialogueTree.h"


DialogueNode::DialogueNode(string Text)
{
	text = Text;
}

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode *NextNode)
{
	text = Text;
	returnCode = ReturnCode;
	nextNode = NextNode;
}

//constructor
DialogueTree::DialogueTree()
{

}

//sets up the tree
void DialogueTree::init()
{



	DialogueNode *node0 = new DialogueNode("Hello brave warrior!\n");
	DialogueNode *node1 = new DialogueNode("I don't want to talk to you.\n");
	DialogueNode *node2 = new DialogueNode("I have a quest for you!\n");
	DialogueNode *node3 = new DialogueNode("You will get 5 gold you greedy swine!\n");
	DialogueNode *node4 = new DialogueNode("Collect ten dandilions.\n");

	//node 0
	node0->dialogueOptions.push_back(DialogueOption("Sup noob!\n", 0, node1));
	node0->dialogueOptions.push_back(DialogueOption("Hello strange voice!\n", 0, node2));
	dialueNodes.push_back(node0);

	//node 1
	node1->dialogueOptions.push_back(DialogueOption("Aww!\n", 0, nullptr));
	dialueNodes.push_back(node1);

	//node 2
	node2->dialogueOptions.push_back(DialogueOption("K bye!\n", 0, nullptr));
	node2->dialogueOptions.push_back(DialogueOption("What is it?\n", 0, node4));
	node2->dialogueOptions.push_back(DialogueOption("What is the pay?\n", 0, node3));
	dialueNodes.push_back(node2);

	//node 3
	node3->dialogueOptions.push_back(DialogueOption("Ok what is it?\n", 0, node4));
	node3->dialogueOptions.push_back(DialogueOption("That sucks I'm out!\n", 0, nullptr));
	dialueNodes.push_back(node3);

	//node 4
	node4->dialogueOptions.push_back(DialogueOption("Lets do it!\n", 1, nullptr));
	node4->dialogueOptions.push_back(DialogueOption("No way!\n", 0, nullptr));
	dialueNodes.push_back(node4);
}
void DialogueTree::destroyTree()
{
	for (int i = 0; i < dialueNodes.size(); i++) {
		delete dialueNodes[i];
	}
	dialueNodes.clear();
}

int DialogueTree::performDialogue()
{
	if (dialueNodes.empty()) {
		return -1;
	}

	DialogueNode *currentNode = dialueNodes[0];

	while (true) {

		cout << currentNode->text << "\n\n";

		for (int i = 0; i < currentNode->dialogueOptions.size(); i++) {
			cout << i + 1 << ": " << currentNode->dialogueOptions[i].text << endl;
		}
		cout << endl;
		int input;
		cin >> input;
		input--;

		if (input < 0 || input > currentNode->dialogueOptions.size()) {
			cout << "Invaild Input!\n";
		} else {
			//check for end of conversation
			if (currentNode->dialogueOptions[input].nextNode == nullptr) {
				return currentNode->dialogueOptions[input].returnCode;
			}

			currentNode = currentNode->dialogueOptions[input].nextNode;
		}
		cout << endl;
	}
}
