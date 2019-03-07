#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

#include <iostream>
#include <assert.h>
template<typename Item>
class BinaryTreeNode {
public:
    BinaryTreeNode(const unsigned int& new_key,const Item& new_data=Item()){
        key_field=new_key;
        data_field=new_data;
        left_link_field=NULL;
        right_link_field=NULL;
    }
    //set variables
    void set_key(const unsigned int& new_key){key_field=new_key;}
    void set_data(const Item& new_key){data_field=new_key;}
    void set_left_link(const BinaryTreeNode*& new_link){left_link_field=new_link;}
    void set_right_link(const BinaryTreeNode*& new_link){left_link_field=new_link;}

    //access variables by refrence
    unsigned int*& key(){return key_field;};
    Item& data(){return data_field;};
    BinaryTreeNode*& left_link(){return left_link_field;};
    BinaryTreeNode*& right_link(){return right_link_field;};

    //access constant variables
    const unsigned int*& key() const{return key_field;};
    const Item& data() const{return data_field;};
    const BinaryTreeNode*& left_link() const{return left_link_field;};
    const BinaryTreeNode*& right_link() const{return right_link_field;};
    //check if node is leaf
    bool is_leaf(){
        if(left_link_field==NULL&&right_link_field==NULL) return true;
        return false;
    }
private:
    unsigned int key_field;
    Item data_field;
    BinaryTreeNode* left_link_field;
    BinaryTreeNode* right_link_field;
};
template<typename Item>
void binary_tree_remove_root(BinaryTreeNode<Item>*& root_ptr);

template<typename Item>
void binary_tree_remove_by_key(BinaryTreeNode<Item>*& root_ptr, unsigned int key_entry);

template<typename Item>
void binary_tree_remove_all(BinaryTreeNode<Item>*& root_ptr);
template<typename Item>
void binary_tree_insert(BinaryTreeNode<Item>*& root_ptr,unsigned int key_entry, Item data_entry=Item());
template<typename Item>
bool binary_tree_search_key(const BinaryTreeNode<Item>*& root_ptr,unsigned int key_entry);
//precondition: key exists in tree
template<typename Item>
void binary_tree_access_data_by_key(const BinaryTreeNode<Item>*& root_ptr,unsigned int key_entry);

//precondition: nonempty tree
template<typename Item>
Item binary_tree_access_key_by_root(const BinaryTreeNode<Item>*& root_ptr);

//precondition: nonempty tree
template<typename Item>
Item binary_tree_access_data_by_root(const BinaryTreeNode<Item>*& root_ptr);

template<typename Item>
Item binary_tree_if_filled(const BinaryTreeNode<Item>*& root_ptr);
#include "BinaryTreeNode.template"
#endif /* BINARYTREENODE_H_ */
