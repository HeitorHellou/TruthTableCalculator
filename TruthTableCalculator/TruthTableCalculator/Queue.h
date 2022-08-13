#pragma once

struct Q_Node
{
	char operand;
	int size;
	int* arr;
	Q_Node* next;
};

class Queue
{
public:
	Queue(); // constructor
	~Queue(); // destructor
	void push(char c); // inserts a node in the queue
	char pop(); // removes a node from the queue
	void print(); // print the queue
private:
	Q_Node* head;
	Q_Node* tail;
};

/* TESTING
Queue* queue = new Queue();
queue->push('A');
queue->push('E');
queue->push('I');
queue->push('O');
queue->push('U');
queue->print();
queue->pop();
queue->pop();
std::cout << "new queue" << std::endl;
queue->print();

delete queue;
*/