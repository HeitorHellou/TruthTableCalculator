#include <iostream>
#include <string>

#include "Util.h"

int main()
{
    int solve{ 1 };
    /*Queue* postfix;
    LinkedList* operands;
    Stack* stack;*/
    while (solve)
    {
        std::string infix; // infix expression entered by the user
        std::cout << "Expression: ";
        std::getline(std::cin, infix);
        infix.erase(remove_if(infix.begin(), infix.end(), isspace), infix.end()); // removing white spaces
        int count = count_unique_operands(infix); // getting total of operands
        int size = (int)pow(2, count); // number of possible configurations

        Queue* postfix = infix_to_postfix(infix); // queue with the expression in postfix format

        LinkedList* operands = new LinkedList(); // list of operands

        // making the list of operands and adding its array values
        std::vector<int> hash(128, 0);
        int pos = 1;
        for (int i{ 0 }; infix[i]; i++)
        {
            if (is_operand(infix[i]))
                hash[infix[i]] = 1;
        }

        for (auto i { 0 }; i < 128; ++i)
        {
            if (hash[i] == 1)
            {
                operands->insert_last(i, count, pos); // Setting up each variable value
                pos++;
            }  
        }

        Stack* stack = new Stack(); // stack where the operation will be performed / the last value remained in the stack will be the answer
        char op;
        // perform operations while there are still operation in the queue
        while (!postfix->is_empty())
        {
            op = postfix->dequeue();
            // if its an operand add to the stack
            if (is_operand(op))
                stack->push_array(operands->get_operand_array(op));
            // else perform the operation and store the result
            else
            {
                switch (op)
                {
                case '!':
                    stack->push_array(negation(stack->pop_array(), size));
                    break;
                case '&':
                    stack->push_array(conjunction(stack->pop_array(), stack->pop_array(), size));
                    break;
                case '+':
                    stack->push_array(disjunction(stack->pop_array(), stack->pop_array(), size));
                    break;
                case '>':
                    stack->push_array(implication(stack->pop_array(), stack->pop_array(), size));
                    break;
                case ':':
                    stack->push_array(biconditional(stack->pop_array(), stack->pop_array(), size));
                    break;
                }
            }
        }

        std::vector<int> res = stack->pop_array(); // getting the final result form the stack

        // printing the answer
        for (auto c : res)
            std::cout << c << std::endl;

        std::cout << "Press ENTER key to Continue" << std::endl;
        std::cin.ignore();

        delete stack;
        delete postfix;
    }

    return 0;
}
