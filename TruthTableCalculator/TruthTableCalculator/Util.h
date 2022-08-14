#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

#include "Queue.h";
#include "Stack.h";
#include "LinkedList.h"

int get_precedence(char op); // gets operator precedence
int is_operand(char c); // check if char is an letter
int count_unique_operands(std::string str); // count unique operands on string
std::vector<int> negation(std::vector<int> arr, int size); // perform the negation operation on the array
std::vector<int> conjunction(std::vector<int> arr, std::vector<int> arr2, int size); // perform the conjunction operation between two arrays
std::vector<int> disjunction(std::vector<int> arr, std::vector<int> arr2, int size); // perform the disjunction operation between two arrays
std::vector<int> implication(std::vector<int> arr, std::vector<int> arr2, int size); // perform the implication operation between two arrays
std::vector<int> biconditional(std::vector<int> arr, std::vector<int> arr2, int size); // perform the biconditional operation between two arrays

Queue* infix_to_postfix(std::string str); // transform the infix operation into postfix
