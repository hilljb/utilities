
/*
 *  linkedListBasic.cpp
 *
 *  utilities library - basic C++ linked list (data type: uint32_t)
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

#include <cstdint>

#include "linkedListBasic.hpp"

namespace utilities { namespace linkedList {


// construct a basic linked list
BasicLinkedList::BasicLinkedList() {
    // allocate the head of the list
    head = new Head32_t;

    // point the head to NULL in both directions
    head->next = 0;
    head->last = 0;
}

// destruct a basic linked list
BasicLinkedList::~BasicLinkedList() {
    // delete inner nodes

    // delete the head
    delete(head);
}

// append an item to a basic linked list
void BasicLinkedList::append(const uint32_t& d) {
    Node32_t*       newNode;

    // allocate a new node
    newNode = new Node32_t;

    // set the data component of the new node
    newNode->data = d;

    // set the next pointer of the new node
    newNode->next = 0;

    // append to end of the list
    if (head->next == 0) { // list is empty
        head->next = newNode;
        head->last = newNode;
    }
    else { // list already has a non-head node
        head->last->next = newNode;
        head->last = newNode;
    }
}


} // namespace linkedList
} // namespace utilities
