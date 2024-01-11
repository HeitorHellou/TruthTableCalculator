#include <iostream>
#include <vector>
#include <cmath>

#include "LinkedList.h"

// constructor
LinkedList::LinkedList()
{
	head = nullptr;
}

// destructor
LinkedList::~LinkedList()
{
	while (head)
	{
		head = head->next;
	}
}

void LinkedList::insert_last(char op, int total, int pos)
{
	int max = (int)pow(2, total); // getting the total of elements an truth table variable will have
	L_Node* node = new L_Node();
	node->operand = op;
	node->size = max;
	node->arr.reserve(max); // array that weill have the truth table values
	// fills the array correspondly with the number of operands
	// 1 - True / 0 - False
	for (int i = 0; i < max; ++i)
		node->arr.push_back((i & (int)pow(2, (total - pos))) == 0);
	node->next = nullptr;

	L_Node* last = head;

	// if the list is empty insert node
	if (head == nullptr)
	{
		head = node;
		return;
	}

	// else traverse to last node
	while (last->next != nullptr)
		last = last->next;

	// change the next of last node
	last->next = node;

	return;
}

std::vector<int> LinkedList::get_operand_array(char op)
{
	L_Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->operand == op)
			return temp->arr;

		temp = temp->next;
	}
}

void LinkedList::print()
{
	L_Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << "operand: " << temp->operand << std::endl;
		for (auto i : temp->arr)
			std::cout << i << std::endl;

		temp = temp->next;
	}
}