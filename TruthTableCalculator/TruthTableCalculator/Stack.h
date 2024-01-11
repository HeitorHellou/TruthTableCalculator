#pragma once

#include <vector>

struct S_Node
{
	char op;
	std::vector<int> arr;
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
	void push_array(std::vector<int> arr);
	std::vector<int> pop_array();
	void print(); // print the stack
private:
	S_Node* head;
};