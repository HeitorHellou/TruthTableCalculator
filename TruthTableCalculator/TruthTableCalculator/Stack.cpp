#include <iostream>

#include "Stack.h"

// constructor
Stack::Stack()
{
	head = nullptr;
}

// destructor
Stack::~Stack()
{
	while (!is_empty())
		pop();
}

// push an character into the stack
void Stack::push(char c)
{
	S_Node* node = new S_Node();
	node->op = c;
	node->next = head;
	head = node;
}

// pop the top element of the stack
char Stack::pop()
{
	if (is_empty())
		return 0;

	S_Node* temp = head;
	head = head->next;
	char popped = temp->op;

	delete temp;

	return popped;
}

// check if the the stack is empty
bool Stack::is_empty()
{
	return head == nullptr;
}

// get the top character in the stack
char Stack::peek()
{
	if (is_empty())
		return 0;

	return head->op;
}

void Stack::push_array(std::vector<int> arr)
{
	S_Node* node = new S_Node();
	node->arr = arr;
	node->next = head;
	head = node;
}

std::vector<int> Stack::pop_array()
{
	if (is_empty())
		return {};
	S_Node* temp = head;
	head = head->next;
	std::vector<int> popped = temp->arr;

	return popped;
}

void Stack::print()
{
	S_Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << "char: " << temp->op << std::endl;
		temp = temp->next;
	}

	delete temp;
}