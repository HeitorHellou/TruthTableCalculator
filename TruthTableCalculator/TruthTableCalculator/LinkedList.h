#pragma once

#include <vector>

struct L_Node
{
	char operand;
	int size;
	std::vector<int> arr;
	L_Node* next;
};

class LinkedList
{
public:
	LinkedList(); // constructor
	~LinkedList(); // destructor
	void insert_last(char op, int total, int pos); // insert a new node at the end of the list
	std::vector<int> get_operand_array(char op);
	void print();
private:
	L_Node* head;
};