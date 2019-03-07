//bag1 is a bag class for integers
#ifndef OREN_BAG1_H
#define OREN_BAG1_H
namespace Oren_BenMeir_ccny_csc212{
    //Value semantics not safe
    class bag1{
    public:
        static const int DEFAULT_CAPACITY=20;
        //Precondition:
        //Postcondition:data and key_holder have a set capacity.
        //Capacity is set and used is 0.
        bag1(int new_capacity);
        //Precondition:
        //Postcondition:data and key_holder set capacity to DEFAULT_CAPACITY.
        //Capacity is set to DEFAULT_CAPACITY and used is 0.
        bag1();
        //precondition:
        //postcondition: Deletes data and key_holder.
        ~bag1();
        //precondition: a key-value pair is inserted
        //postcondition:A key-value pair is created, if the key inserted before was
        // already set, then the value for that key will be overwritten.
        void insert(int key, int value);
        //precondition: the key exists in the object
        //postcondition: the key-value pair is removed
        void remove(int key);
        //precondition: the key exists in the object
        //postcondition: the value in the key-value pair is retrieved
        int retrieve(int key);
        //precondition: the key exists in the object
        //postcondition: the value in the key-value pair is retrieved
        // by setting retriever to be the value that is retrieved
        void retrieve(int key, int& retriever);
    private:
        //precondition: start<end
        //postcondition: returns the location of the integer in an array if it exists,
        //otherwise it returns -1.
        int search(int* a,  int key, int first, int last);
        int capacity;
        int used;
        int *data;
        int *key_holder;
    };

}
#endif

