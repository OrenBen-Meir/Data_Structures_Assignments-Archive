#ifndef HASHBUCKET_H_
#define HASHBUCKET_H_

template<typename Item>
#include <iostream>
#include "LinkedListNode.h"
#include "BinaryTreeNode.h"
class HashBucket {
public:
    static const unsigned int LINKED_LIST_THREASHOLD=12;
    static const unsigned int BINARY_TREE_THREASHOLD=7;
    HashBucket();
    virtual ~HashBucket();
    void insert(unsigned int new_key, Item new_data=Item());
    void erase(unsigned int key_entry);
    void erase_all();
    bool search(unsigned int key_entry);
    //Precondition: rehashing function is activated;
    void erase_top();
    //precondition: key exists
    Item access(unsigned int key_entry) const;
    //Precondition: hash bucket is not empty
    Item top_data() const;
    //Precondition: hash bucket is not empty
    unsigned int top_key() const;
    bool if_filled() const;
    unsigned int size() const;
private:
    void convert_link_to_binary();
    void convert_binary_to_link();
    LinkedListNode<Item>* head_ptr;
    BinaryTreeNode<Item>* root_ptr;
    unsigned int used;
};
#include "HashBucket.template"
#endif /* HASHBUCKET_H_ */

