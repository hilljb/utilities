
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

#ifndef UTILITIES_LINKEDLIST_BASIC_HPP
#define UTILITIES_LINKEDLIST_BASIC_HPP

#include <cstdint>

namespace utilities { namespace linkedList {

/*****************************************************************************/
/* Linked list node (holds a uint32_t and points to the next node)           */
/*****************************************************************************/
class Node32_t {
    public:
        uint32_t        data;
        Node32_t*       next;
};


/*****************************************************************************/
/* Linked list head (points to the first and last nodes in the list)         */
/*****************************************************************************/
class Head32_t {
    public:
        Node32_t*       next;
        Node32_t*       last;
};


/*****************************************************************************/
/* Basic linked list class (holds a list of uint32_t's and related methods)  */
/*****************************************************************************/
class BasicLinkedList {
    private:
        Head32_t*       head;
        uint32_t        length;

    public:
        // class constructor
        BasicLinkedList();

        // class destructor
        ~BasicLinkedList();

        // push item to list
        void push(uint32_t d);

        // pop item from list
        uint32_t pop();
};


} // namespace linkedList
} // namespace utilities

#endif
