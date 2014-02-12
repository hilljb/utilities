
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


class Node32_t {
    public:
        uint32_t        data;
        Node32_t*       next;
};

class Head32_t {
    public:
        Node32_t*       next;
        Node32_t*       last;
};


class BasicLinkedList {
    private:
        Head32_t*       head;

    public:
        // class constructor
        BasicLinkedList();

        // class destructor
        ~BasicLinkedList();

        // append item to list
        void append(const uint32_t& d);

};


} // namespace linkedList
} // namespace utilities

#endif
