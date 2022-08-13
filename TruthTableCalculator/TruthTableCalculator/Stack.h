#pragma once

struct S_Node
{
	char op;
	int* arr;
	S_Node* next;
};

class Stack
{
public:
	Stack(); // constructor
	~Stack(); // destructor
	void push(char c); // push a character into the stack
	char pop(); // pop the stack
	bool is_empty(); // check if the stack is empty
	char peek(); // return the top element of the stack
	void print(); // print the stack
private:
	S_Node* head;
};

/* TESTING
Stack* stack = new Stack();
stack->push('A');
stack->push('E');
stack->push('I');
stack->push('O');
stack->push('U');
stack->print();
stack->pop();
std::cout << "peek: " << stack->peek() << std::endl;
stack->pop();
stack->print();

delete stack;
*/