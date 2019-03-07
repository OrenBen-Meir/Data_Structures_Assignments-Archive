//Hash table class, questions will be answered in the bottom.
// HashBucket is the class that represents the bash bucket
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashBucket.h"
template<typename Item>
class HashTable {
public:
    static const unsigned int DEFAULT_CAPACITY=100;
    HashTable(unsigned int new_capacity=DEFAULT_CAPACITY);
    ~HashTable();
    void insert(unsigned int key_entry,Item data_entry);
    void erase(unsigned int key_entry);
    void erase_all();
    bool search(unsigned int key_entry);
    //precondition: key exists
    Item access(unsigned int key_entry) const;
    unsigned int size() const;
private:
    void rehash();
    unsigned int capacity;
    unsigned int threshold;
    unsigned int used;
    HashBucket<Item>* table;
};
#include "HashTable.template"
#endif /* HASHTABLE_H_ */
/* It is advantageous to convert a linked list to a binary tree if the number of entries in the hash bucket are 12 and
 * advantageous to convert a  binary tree to a linked list if the number of entries are 7 because a linked list
 * holds less memory so despite slower on average to access and modify data than a binary tree,
 * the linked list can instead make up for it with having less items needed to traverse.
 * However this memory efficiency becomes a burden as newer items are added as it takes much longer to
 * access and modify the data in a linked list on average than compared to a binary
 * tree so it becomes advantageous to convert the linked list to a binary tree.
 * The running time for a binary tree is logarithmic on average and the running time
 * for a linked list is on average linear and O(n)>O(log n).
 *
 * In order to resize an array of a rehash table, a rehash function is needed. It is called rehash since the capacity
 * changes, so does the hash value for each key changes.
 */

