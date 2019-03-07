// Node that stores data
#ifndef MYNODE_H_
#define MYNODE_H_

#include "keyNode.h"
class myNode {
public:
// TYPEDEF
    typedef double value_type;
// CONSTRUCTOR
    myNode( const value_type& init_data = value_type( ), keyNode* init_link = NULL );
// Member functions to set the data and link fields to keys:
    void set_data(const value_type& new_data);
    void set_link_to_key(keyNode* new_link);
// Constant member function to retrieve the current data:
    value_type data( ) const;
// Two slightly different member functions to retrieve the link to the key:
    const keyNode* link_to_key( ) const;
    keyNode* link_to_key( );
private:
    value_type data_field;
    keyNode* link_field;
};
#endif /* MYNODE_H_ */

