
/*
 *  linkedListNaive.cpp
 *
 *  utilities library - naive C++ linked list (data type: uint32_t)
 *  Copyright (C) 2014  Jason B. Hill (jason@jasonbhill.com)
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or (at
 *  your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 *  License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library; if not, write to the Free Software Foundation,
 *  Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

// Load uint32_t datatype
#include <cstdint>

// Load prototyped class/methods
#include "linkedListNaive.hpp"

// place in the utilities::linkedList::naive namespace
namespace utilities {
namespace linkedList {
namespace naive {


/*****************************************************************************/
/* Naive linked list constructor                                             */
/*****************************************************************************/
LinkedList::LinkedList() {
    // allocate memory for the head of the list
    head = new Head32_t;

    // initialize the list with no nodes
    head->first = 0;
}


/*****************************************************************************/
/* Naive linked list destructor                                              */
/*****************************************************************************/
LinkedList::~LinkedList() {
    Node32_t*       iterNode;

    // delete nodes until no nodes exist
    while (head->first != 0) {
        iterNode = head->first;
        head->first = iterNode->next;
        delete(iterNode);
    }

    // delete head
    delete(head);
}


// get the length of the list
uint32_t LinkedList::getLength() {
    uint32_t        length = 0;
    Node32_t*       iterNode;

    iterNode = head->first;
    while (iterNode != 0) {
        iterNode = iterNode->next;
        length++;
    }

    return length;
}


// push item onto end of list
void LinkedList::push(uint32_t d) {
    Node32_t*       newNode;
    Node32_t*       iterNode;

    // allocate a new node
    newNode = new Node32_t;

    // set the 'data' component of the new node
    newNode->data = d;

    // set the 'next' component of the new node to NULL (end of list)
    newNode->next = 0;

    // determine if this is the first node in the list
    if (head->first == 0) {
        // point the head to this node, the first node in the list
        head->first = newNode;
    } else {
        // find the end of the current list, and point that node to newNode
        iterNode = head->first;
        while (iterNode->next != 0) iterNode = iterNode->next;
        iterNode->next = newNode;
    }
}


// pop an item from a basic linked list (length > 0)
uint32_t LinkedList::pop() {
    uint32_t        d;
    Node32_t*       node;

    // find the end of the list
    
}

} // naive
} // namespace linkedList
} // namespace utilities
