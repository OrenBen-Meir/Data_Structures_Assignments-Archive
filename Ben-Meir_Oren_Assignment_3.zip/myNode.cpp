#include "myNode.h"
#include "keyNode.h"
#include <iostream>

myNode::myNode( const myNode::value_type& init_data, keyNode* init_link) { data_field = init_data; link_field = init_link; }
void myNode::set_data(const myNode::value_type& new_data) { data_field = new_data; }
void myNode::set_link_to_key(keyNode* new_link) { link_field = new_link; }
myNode::value_type myNode::data( ) const { return data_field; }
const keyNode* myNode::link_to_key( ) const { return link_field; }
keyNode* myNode::link_to_key( ) { return link_field; }

