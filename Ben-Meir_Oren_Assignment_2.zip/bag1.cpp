#include <assert.h>
#include "bag1.h"

namespace Oren_BenMeir_ccny_csc212{

    bag1::bag1(int new_capacity){
        capacity=new_capacity;
        used=0;
        data=new int[new_capacity];
        key_holder=new int[new_capacity];
    }
    bag1::bag1(){
        capacity=DEFAULT_CAPACITY;
        used=0;
        data=new int[DEFAULT_CAPACITY];
        key_holder=new int[DEFAULT_CAPACITY];
    }
    bag1::~bag1(){
        delete[] data;
        delete[] key_holder;
    }

    void bag1::insert(int key, int value){
        if(used==capacity){
            capacity=2*used;
            int *key_deleter,*data_deleter;
            int* new_data=new int[capacity];
            int* new_key_holder=new int[capacity];
            for(int i=0;i<used;i++){
                new_data[i]=data[i];
                new_key_holder[i]=key_holder[i];
            }
            data_deleter=data;
            key_deleter=key_holder;
            data=new_data;
            key_holder=new_key_holder;
            new_data=data_deleter;
            new_key_holder=key_deleter;
            delete new_data;
            delete new_key_holder;
        }
        int location=search(key_holder,key, 0, used-1);
        if(location!=-1){
            data[location]=value;
            return;
        }
        int i;
        for(i=used-1;i>0&&key_holder[i]>key;i--){
            key_holder[i+1]=key_holder[i];
            data[i+1]=data[i];
        }
        key_holder[i+1]=key;
        data[i+1]=value;
        used++;
    }

    void bag1::remove(int key){
        int location=search(key_holder,key, 0, used-1);
        if(location==-1) return;
        --used;
        data[location]=data[used];
        key_holder[location]=key_holder[used];
    }

    int bag1::retrieve(int key){
        int location=search(key_holder,key, 0, used-1);
        assert(location!=-1);
        return data[location];
    }

    void bag1::retrieve(int key, int& retriever){
        int location=search(key_holder,key, 0, used-1);
        if(location!=-1) retriever=data[location];
    }

    int bag1::search(int* a,int key, int first, int last) {
        if(first>last) return -1;
        int mid=(first+last)/2;
        if (key==a[mid])return mid;
        else if (key<a[mid]) return search(a, key, first, mid-1);
        else return search(a, key, mid+1, last);
    }
}

