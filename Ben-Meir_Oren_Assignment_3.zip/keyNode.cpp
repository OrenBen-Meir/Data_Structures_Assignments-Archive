#include "keyNode.h"
#include "myNode.h"
#include<iostream>
keyNode::keyNode( const int& init_key, myNode* init_link) { key_field = init_key; link_field = init_link; }
void keyNode::set_key(const int& new_key) { key_field = new_key; }
void keyNode::set_link_to_data(myNode* new_link) { link_field = new_link; }
int keyNode::key( ) const { return key_field; }
const myNode* keyNode::link_to_data( ) const { return link_field; }
myNode* keyNode::link_to_data( ) { return link_field; }
