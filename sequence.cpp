#include <cstdlib>
#include <iostream>
#include "sequence.h"

namespace coen70_lab6 {

    // CONSTRUCTORS and DESTRUCTOR

    sequence::sequence() {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
    }

    sequence::sequence(const sequence& source) {
        //check for self-assignment
	if(this != &source) {
            list_clear(head_ptr);
            many_nodes = 0;
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            many_nodes = source.many_nodes;
            precursor = list_locate(head_ptr, many_nodes);
            cursor = precursor->link();         
        }
    }

    sequence::~sequence() {
        list_clear(head_ptr);
        many_nodes = 0;
    }

    // MODIFICATION MEMBER FUNCTIONS

    void sequence::start() {
        cursor = head_ptr;
        precursor = NULL;
    }

    void sequence::end() {
        cursor = tail_ptr;
        precursor = cursor;
    }

    void sequence::advance() {
        if (is_item()) {
            if (cursor->link() == 0) {
                precursor = NULL;
                cursor = NULL;
            } else {
                precursor = cursor;
                cursor = cursor->link();
            }
        }
    }

    void sequence::insert(const value_type& entry) {
        if (cursor == 0 || cursor == head_ptr) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
        } else {
            list_insert(precursor, entry);
            cursor = precursor->link();
        }

        many_nodes = list_length(head_ptr);
        tail_ptr = list_locate(head_ptr, many_nodes);
    }

    void sequence::attach(const value_type& entry) {
        if (head_ptr == 0) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
        } else if (cursor == head_ptr) {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
        } else if (cursor == 0 || cursor == tail_ptr) {
            node *new_node = new node;
            new_node->set_data(entry);
            cursor = tail_ptr;
            cursor->set_link(new_node);
            precursor = cursor;
            cursor = cursor->link();
        } else {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
        }
        many_nodes = list_length(head_ptr);
        tail_ptr = list_locate(head_ptr, many_nodes);
    }

    void sequence::operator=(const sequence& source) {
        //check for self-assignment
	if(this != &source) {
            list_clear(head_ptr);
            many_nodes = 0;
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            many_nodes = source.many_nodes;
            precursor = list_locate(head_ptr, many_nodes);
            cursor = precursor->link();         
        }
    }

    void sequence::remove_current() {
        if (is_item()) {
            if (cursor == head_ptr) {
                if (cursor->link() != 0) {
                    list_head_remove(head_ptr);
                    cursor = head_ptr;
                    precursor = NULL;
                } else { //cursor->link == 0
                    list_clear(head_ptr);
                    cursor = NULL;
                    precursor = NULL;
                }
            } else if (cursor->link() == 0) {
                list_remove(precursor);
                cursor = NULL;
                precursor = NULL;
            } else {
                list_remove(precursor);
                cursor = precursor->link();
            }
            many_nodes = list_length(head_ptr);
        }
    }

    // CONSTANT MEMBER FUNCTIONS
    /*
     * See header file for implementation of constant member functions 
     */
}
