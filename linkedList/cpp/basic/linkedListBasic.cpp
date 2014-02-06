
/*
 *  linkedListBasic.cpp
 *
 *  utilities library - basic C++ linked list
 *
 *  Copyright (C) 2014  Jason B. Hill (jason@jasonbhill.com)
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "linkedListBasic.hpp"

namespace utilities { namespace linkedList {

// construct a basic linked list
BasicLinkedList::BasicLinkedList() {
    // allocate the head and tail
    head = new node_t;
    tail = new node_t;

    // point the head to the tail and point the tail to the head
    head->next = tail;
    tail->next = head;

    // make the objects of the head and tail NULL
    head->obj = 0;
    tail->obj = 0;
}

// destruct a basic linked list (the objects at each node should be cleared)
BasicLinkedList::~BasicLinkedList() {
    // delete middle node structs here

    // delete the head and tail structs
    delete(head);
    delete(tail);
}

// append an item to a linked list
void BasicLinkedList::append(void* obj) {
    // allocate a new node
    node new_node = new node_t;

    // store obj pointer in node
    new_node->obj = obj;

    // set links
    // reset final link as follows:
    // 1) reset the link from tail to the last non-trivial node
    tail->next->next = new_node;
    // 2) reset the link from the last non-trivial node
    tail->next = new_node;
    // 3) make the new last node point to the tail
    new_node->next = tail;
}


} // namespace linkedList
} // namespace utilities
