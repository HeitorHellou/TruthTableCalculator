#include "Util.h"

// checks operator precedence and return the value
// operator precedence is a set of rules that reflects which procedures to perform first
int get_precedence(char op)
{
	switch (op)
	{
	case '!': // negation
		return 5;
	case '&': // conjunction
		return 4;
	case '+': // disjunction
		return 3;
	case '>': // implication
		return 2;
	case ':': // biconditional
		return 1;
	}
}

// check if the char is an operand, a letter in this case
int is_operand(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int count_unique_operands(std::string str)
{
	std::vector<int> hash(128, 0); // there is 128 characters each represented by a unique integer value -> ASCII code
	int c = 0;

	for (int i { 0 }; str[i]; ++i)
	{
		// only add the char that are operands
		// set the position correspondent to the ASCII value to 1
		if (is_operand(str[i]))
			hash[str[i]] = 1;
	}

	for (auto i : hash)
		c += i;

	return c;
}

// perform the negation operation on the array values
std::vector<int> negation(std::vector<int> arr, int size)
{
	for (int i{ 0 }; i < size; ++i)
		arr[i] = !arr[i];

	return arr;
}

// perform the conjunction operation on the array values
std::vector<int> conjunction(std::vector<int> arr, std::vector<int> arr2, int size)
{
	std::vector<int> res;
	res.reserve(size);

	for (int i { 0 }; i < size; ++i)
		res.push_back(arr[i] && arr2[i]);

	return res;
}

// perform the disjunction operation on the array values
std::vector<int> disjunction(std::vector<int> arr, std::vector<int> arr2, int size)
{
	std::vector<int> res;
	res.reserve(size);

	for (int i{ 0 }; i < size; ++i)
		res.push_back(arr[i] || arr2[i]);

	return res;
}

// perform the implication operation on the array values
std::vector<int> implication(std::vector<int> arr, std::vector<int> arr2, int size)
{
	std::vector<int> res;
	res.reserve(size);

	for (int i{ 0 }; i < size; ++i)
		res.push_back(!arr[i] || arr2[i]);

	return res;
}

// perform the biconditional operation on the array values
std::vector<int> biconditional(std::vector<int> arr, std::vector<int> arr2, int size)
{
	std::vector<int> res;
	res.reserve(size);

	for (int i{ 0 }; i < size; ++i)
		res.push_back(arr[i] == arr2[i]);

	return res;
}

// this is an implementation of the shunting yard algorithm
// when traversing an expression to alter it form infix to postfix perform some operations
// if the character is a operand add to the queue
// if its a operator we need to make some tests
// if the operator is '(' or the stack is empty push into the stack
// it its a ')' pop everything until you find a '('
// if the precedence of the operator at the top of the stack is lesser than the scanned character, push into the stack
// if the precedence of the operator at the top of the stack is greater, pop the stack and add it to the queue than push the scanned operator to the stack
// repeat it until all characters are read
Queue* infix_to_postfix(std::string str)
{
	Stack* stack = new Stack(); // initializing the stack
	Queue* queue = new Queue(); // initializing the queue

	for (auto c : str)
	{
		if (is_operand(c))
			queue->enqueue(c);
		else if (c == '(')
			stack->push(c);
		else
		{
			if (c == ')')
			{
				while (!stack->is_empty() && stack->peek() != '(')
					queue->enqueue(stack->pop());
				stack->pop();
			}
			else
			{
				if (stack->is_empty())
					stack->push(c);
				else if (get_precedence(c) <= get_precedence(stack->peek()))
				{
					queue->enqueue(stack->pop());
					stack->push(c);
				}
				else
					stack->push(c);
			}
		}
	}

	while (!stack->is_empty())
		queue->enqueue(stack->pop());

	return queue;
}