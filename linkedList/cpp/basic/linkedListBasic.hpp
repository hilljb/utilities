
/*
 *  linkedListBasic.hpp
 *
 *  utilities library - basic C++ linked list
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

#ifndef UTILITIES_LINKEDLIST_BASIC_HPP
#define UTILITIES_LINKEDLIST_BASIC_HPP

namespace utilities { namespace linkedList {


typedef struct node_t {
    void*       obj;
    node_t*     next;
} * node;

class BasicLinkedList {
    private:
        node    head;
        node    tail;

    public:
        // class constructor
        BasicLinkedList();

        // class destructor
        ~BasicLinkedList();

        // append list item with pointer to obj
        void append(void* obj);
};


} // namespace linkedList
} // namespace utilities

#endif
