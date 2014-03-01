
#include <iostream>
#include <cstdint>

#include "linkedListNaive.hpp"




int main(void) {

    // example running on the stack
    utilities::linkedList::naive::LinkedList    L;
    uint32_t    listLen;;

    L.push(2);
    L.push(5);

    listLen = L.getLength();

    std::cout << listLen << std::endl;


    // example dynamically allocated
    utilities::linkedList::naive::LinkedList*   M;

    M = new utilities::linkedList::naive::LinkedList;

    listLen = M->getLength();
    std::cout << listLen << std::endl;

    delete(M);


    return 0;
}
