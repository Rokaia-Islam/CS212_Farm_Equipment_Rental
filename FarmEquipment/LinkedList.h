#include <iostream>
#include <string>
#include "Records.h"
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList {
private:
    struct Node {
        Equipment data;
        Node* next;
    };


public:
    LinkedList();
    ~LinkedList();

    bool insertEnd(const Equipment& e);   // false if the ID already exists
    bool deleteById(int id);              // false if not found
    Equipment* findById(int id);          // pointer, or nullptr
    void display() const;                 // prints all equipment as a table
    bool isEmpty() const;
    int size() const;
    int toArray(Equipment arr[], int maxSize) const;   // returns number copied
};

#endif