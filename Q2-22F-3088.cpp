#include<iostream>
#include<string>
using namespace std;
class myStack {
	struct node {
		string data;
		node* next;
		node(string value)
		{
			data = value;
			next = NULL;
		}
	};
	//variable
	node* top;
	int size = -1;
public:
	//constructor
	myStack() {
		top = NULL;
	}
	//check the empty status
	bool isEmpty() {
		return size == -1;
	}
	//push the elements on the stack
	void push(string value) {
		node* n = new node(value);
		if (isEmpty()) {
			top = n;
		}
		else {
			n->next = top;
			top = n;
		}
		size += 1;
	}
	//pop the elements
	string pop() {
		if (isEmpty())
		{
			cout << "CAN NOT POP BECAUSE THE STACK IS EMPTY\n";
			return "";
		}
		string myString;
		myString = top->data;
		node* temp = top;
		top = top->next;
		delete temp;
		size = size - 1;
		return myString;
	}
	//display the stack
	void stackDisplay() {
		if (isEmpty()) {
		cout << "HRS Stack Empty";
			return;
		}
		myStack tempStack; // Temporary stack so our orignal data not lost
		cout << "Stack: ";
		while (!isEmpty()) {
		string value = pop();
		cout << value << "<-";
		tempStack.push(value);
		}
		// Push elements back to the original stack
		while (!tempStack.isEmpty()) {
		push(tempStack.pop());
		}
	}
	//clear the stack
	void clearMyStack() {
		while (!isEmpty())
		{
			pop();
		}
	}
};
void myTextEditor() {
	//here we make stacks objects ,keunk hmne operation perform krny hain
	myStack textStack;
	myStack undoStack;
	myStack redoStack;
	string command;
	do
	{
		//for undo
		if (textStack.isEmpty())
		{
			cout << "[ UNDO : DISABLED.";
		}
		else {
			cout << "[ UNDO : ENABLED.";
		}
		//for redo
		if (undoStack.isEmpty())
		{
			cout << " REDO : DISABLED.]";
		}
		else {
			cout << " REDO : ENABLED.]";
		}
		cout << endl;
		cout << "----------------------------------\n";
		cout << "TYPE YOUR COMMAND :";
		getline(cin, command);
		if (command == "quit" || command == "Quit" || command == "QUIT")
		{
			cout << "Program terminating." << endl;
			break;
		}
		//operations
		if (command == "undo" || command == "Undo" || command == "UNDO") {
			if (!textStack.isEmpty())
			{
				string str = textStack.pop();
				cout << str << "  Undone" << endl;
				undoStack.push(str);
			}
			else {

			}
		}
		else if(command == "redo" || command == "Redo" || command == "REDO"){
			if(!undoStack.isEmpty())
			{
				string str = undoStack.pop();
				cout << str << " Redone" << endl;
				textStack.push(str);
			}
			else {

			}
		}
		else {
			undoStack.clearMyStack();
			textStack.push(command);
		}
		//it will display the stacks
		cout << "----------------------------------\n";
		cout << "TEXT :";
		textStack.stackDisplay();
		cout << endl;
		cout << "UNDO :";
		undoStack.stackDisplay();
		cout << endl;
		/*cout << "REDO :";
		redoStack.stackDisplay();
		cout << endl;*/
		cout << "----------------------------------\n";
	} while (command!="quit" && command != "Quit" && command != "QUIT");
}
int main()
{
	myTextEditor();
	return 0;
}
