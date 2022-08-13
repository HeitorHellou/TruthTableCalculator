#include <iostream>

#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

int main()
{
    LinkedList* list = new LinkedList();
    list->insert_last('P', 3, 1);
    list->insert_last('Q', 3, 2);
    list->insert_last('R', 3, 3);
    std::vector<int> arr = list->get_operand_array('P');
    list->print();
    return 0;
}
