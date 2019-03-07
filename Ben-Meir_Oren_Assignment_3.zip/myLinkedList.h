// Linked List that stores a key-value pair
#ifndef MYLINKEDLIST_H_
#define MYLINKEDLIST_H_
#include "keyNode.h"
#include "myNode.h"
class myLinkedList {
public:
    myLinkedList();
    ~myLinkedList();
    //postcondition: keys are numerically sorted from lowest to highest
    // the expected run time of the function would be O(n^2)
    void sort_key();
    //postcondition: if the key exists, the data is changed,
    //else a new key-data pair is inserted.
    void insert(int new_key,myNode::value_type new_entry);
    //postcondition: a key-data pair is removed based on the key inputted,
    //if key doesn't exist, nothing happens
    void remove(int key_entry);
    //postcondition: the entire linked list is deleted
    void remove_all();
    //precondition: the key inputed exists in the linked list
    //postcondition: the data from the key-data pair is retrieved
    myNode::value_type access(int key_entry);
    //postcondition: returns size of list
    unsigned int list_size() const;
private:
    //postcondition: the entire linked list starting from key_head is deleted
    void erase_list_from(keyNode* key_head);
    keyNode* starter;
    unsigned int size;
};

#endif /* MYLINKEDLIST_H_ */
