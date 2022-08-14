#pragma once

struct Q_Node
{
	char character;
	Q_Node* next;
};

class Queue
{
public:
	Queue(); // constructor
	~Queue(); // destructor
	void enqueue(char c); // inserts a node in the queue
	char dequeue(); // removes a node from the queue
	bool is_empty(); // check if head of queue == null
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