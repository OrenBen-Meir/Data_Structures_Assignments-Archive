//Node that stores a key

#ifndef KEYNODE_H_
#define KEYNODE_H_
#include <iostream>
#include "myNode.h"
class keyNode {
public:
// CONSTRUCTOR
    keyNode( const int& init_key = int( ), myNode* init_link = NULL );
// Member functions to set the data and link fields to data:
    void set_key(const int& new_data);
    void set_link_to_data(myNode* new_link);
// Constant member function to retrieve the current key:
    int key( ) const;
// Two slightly different member functions to retrieve the link to the data:
    const myNode* link_to_data( ) const;
    myNode* link_to_data( );
private:
    int key_field;
    myNode* link_field;
};
#endif /* KEYNODE_H_ */
