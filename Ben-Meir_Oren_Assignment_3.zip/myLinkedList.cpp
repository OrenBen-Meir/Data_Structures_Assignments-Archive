#include "myLinkedList.h"
#include "keyNode.h"
#include "myNode.h"
#include <iostream>
#include <assert.h>
myLinkedList::myLinkedList() {
    starter=NULL;
    size=0;
}

myLinkedList::~myLinkedList() {
    remove_all();
}

void myLinkedList::sort_key(){
    int keyStore;
    myNode::value_type valstore;
    keyNode* pivot=starter;
    while(pivot!=NULL){
        keyNode* check=(pivot->link_to_data())->link_to_key();
        int keyStore=pivot->key();
        myNode::value_type valstore=(pivot->link_to_data())->data();
        while(check!=NULL){
            if(pivot->key() > check->key()){
                pivot->set_key(check->key());
                (pivot->link_to_data())->set_data((check->link_to_data())->data());
                check->set_key(keyStore);
                (check->link_to_data())->set_data(valstore);
            }
            check=(check->link_to_data())->link_to_key();
        }
        pivot=(pivot->link_to_data())->link_to_key();
    }
}

void myLinkedList::insert(int new_key,myNode::value_type new_entry){
    if(starter==NULL){
        size++;
        starter= new keyNode(new_key,new myNode(new_entry));
    }
    keyNode* current=starter;
    keyNode* next=(starter->link_to_data())->link_to_key();
    while(next!=NULL){
        if(current->key()==new_key){
            (current->link_to_data())->set_data(new_entry);
            return;
        }
        current=(current->link_to_data())->link_to_key();
        next=(next->link_to_data())->link_to_key();
    }
    size++;
    keyNode* NewNode=new keyNode(new_key,new myNode(new_entry));
    (current->link_to_data())->set_link_to_key(NewNode);
}

void myLinkedList::remove(int key_entry){
    if(starter->key()==key_entry){
        keyNode* new_starter=(starter->link_to_data())->link_to_key();
        delete starter->link_to_data();
        delete starter;
        starter=new_starter;
        size--;
        return;
    }
    keyNode* previous=starter;
    keyNode* current=(starter->link_to_data())->link_to_key();
    while(current!=NULL){
        if(current->key()==key_entry){
            (previous->link_to_data())->set_link_to_key((current->link_to_data())->link_to_key());
            delete current->link_to_data();
            delete current;
            size--;
            return;
        }
    }
}

void myLinkedList::remove_all(){
    erase_list_from(starter);
    size=0;
}

void myLinkedList::erase_list_from(keyNode* key_head){
    if(key_head==NULL) return;
    erase_list_from((key_head->link_to_data())->link_to_key());
    delete key_head->link_to_data();
    delete key_head;
}

myNode::value_type myLinkedList::access(int key_entry){
    keyNode* current=starter;
    while(current!=NULL){
        if(current->key()==key_entry){
            return (current->link_to_data())->data();
        }
        current=(current->link_to_data())->link_to_key();
    }
    assert(current!=NULL);
    return 0;
}

unsigned int myLinkedList::list_size() const{return size;}
