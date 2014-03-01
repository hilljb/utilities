
/*
 *  linkedLisNaive.hpp
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

#ifndef UTILITIES_LINKEDLIST_NAIVE_HPP
#define UTILITIES_LINKEDLIST_NAIVE_HPP

#include <cstdint>

// place in the utilities::linkedList::naive namespace
namespace utilities {
namespace linkedList {
namespace naive {

/*****************************************************************************/
/* Linked list node                                                          */
/* Holds a uint32_t and points to the next node.                             */
/*****************************************************************************/
class Node32_t {
    public:
        uint32_t        data; // the data for this node
        Node32_t*       next; // pointer to the next node
};


/*****************************************************************************/
/* Linked list head                                                          */
/* Holds a pointer to the first node of the list.                            */
/*****************************************************************************/
class Head32_t {
    public:
        Node32_t*       first; // pointer to the first node
};


/*****************************************************************************/
/* Basic linked list class (holds a list of uint32_t's and related methods)  */
/*****************************************************************************/
class LinkedList {
    private:
        Head32_t*       head; // each list has a head (not public)

    public:
        // class constructor
        LinkedList();

        // class destructor
        ~LinkedList();

        // get the length of the list
        uint32_t getLength();

        // push item onto end of list
        void push(uint32_t d);

        // pop item from end of list - returns the popped item
        uint32_t pop();

        // print function
        void print();
};

} // namespace naive
} // namespace linkedList
} // namespace utilities

#endif // #ifndef UTILITIES_LINKEDLIST_NAIVE_HPP
