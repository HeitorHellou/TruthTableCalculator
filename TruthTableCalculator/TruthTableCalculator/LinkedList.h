#pragma once

#include <vector>

// will be used to store an operand and an array with its possible combinations
// example:
// P
// 1 / 0
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

// TESTING
//LinkedList* list = new LinkedList();
//list->insert_last('P', 3, 1);
//list->insert_last('Q', 3, 2);
//list->insert_last('R', 3, 3);
//std::vector<int> arr = list->get_operand_array('P');
//list->print();
//
//delete list;