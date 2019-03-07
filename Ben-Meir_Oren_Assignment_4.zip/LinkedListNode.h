#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_


template<typename Item>
#include <iostream>
class LinkedListNode {
public:
    LinkedListNode(const unsigned int& new_key,const Item& new_data=Item(), const LinkedListNode*& new_link=NULL){
        key_field=new_key;
        data_field=new_data;
        link_field=new_link;
    }
    //set variables
    void set_key(const unsigned int& new_key){key_field=new_key;}
    void set_data(const Item& new_key){data_field=new_key;}
    void set_link(const LinkedListNode*& new_link){link_field=new_link;}

    //access variables by refrence
    unsigned int*& key(){return key_field;};
    Item& data(){return data_field;};
    LinkedListNode*& link(){return link_field;};

    //access constant variables
    const unsigned int*& key() const{return key_field;};
    const Item& data() const{return data_field;};
    const LinkedListNode*& link() const{return link_field;};
private:
    unsigned int key_field;
    Item data_field;
    LinkedListNode* link_field;
};

template<typename Item>
void linked_list_remove_by_key(LinkedListNode<Item>*& head_ptr,const unsigned int& key_entry);

template<typename Item>
void linked_list_remove_head(LinkedListNode<Item>*& head_ptr);

template<typename Item>
void linked_list_insert(LinkedListNode<Item>*& head_ptr, const unsigned int& key_entry,const Item& data_entry=Item());

template<typename Item>
bool linked_list_search_key(const LinkedListNode<Item>*& head_ptr, const unsigned int& key_entry);

//precondition: key exists
template<typename Item>
Item linked_list_access_data_by_key(const LinkedListNode<Item>*& head_ptr, const unsigned int& key_entry);

//precondition: nonempty linked list
template<typename Item>
Item linked_list_access_key_by_head(const LinkedListNode<Item>*& head_ptr);

//precondition: nonempty linked list
template<typename Item>
Item linked_list_access_data_by_head(const LinkedListNode<Item>*& head_ptr);

template<typename Item>
Item linked_list_remove_all(LinkedListNode<Item>*& head_ptr);
template<typename Item>
Item linked_list_if_filled(const LinkedListNode<Item>*& head_ptr);
#include "LinkedListNode.template"
#endif /* LINKEDLISTNODE_H_ */