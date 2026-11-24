#include "ReturnStack.h"
#include <iostream>

using namespace std;

ReturnStack::ReturnStack() : topNode(nullptr), currentSize(0) {}

ReturnStack::~ReturnStack() {
    clear();
}

bool ReturnStack::isEmpty() const {
    return topNode == nullptr;
}

int ReturnStack::size() const {
    return currentSize;
}

bool ReturnStack::push(const ReturnRecord& rec) {
    StackNode* newNode = new StackNode(rec, topNode);
    if (!newNode) {
        return false;
    }
    topNode = newNode;
    currentSize++;
    return true;
}

bool ReturnStack::pop(ReturnRecord& removedRecord) {
    if (isEmpty()) {
        return false;
    }
    StackNode* temp = topNode;
    removedRecord = temp->data;
    topNode = topNode->next;
    delete temp;
    currentSize--;
    return true;
}

bool ReturnStack::peek(ReturnRecord& topRecord) const {
    if (isEmpty()) {
        return false;
    }
    topRecord = topNode->data;
    return true;
}

void ReturnStack::displayAll() const {
    if (isEmpty()) {
        cout << "No return records in stack." << endl;
        return;
    }

    StackNode* current = topNode;
    int index = 1;
    while (current != nullptr) {
        cout << index++ << ") Return Date: " << current->data.returnDate
             << " | Condition: " << current->data.condition << endl;
        current = current->next;
    }
}

void ReturnStack::clear() {
    while (!isEmpty()) {
        ReturnRecord dummy;
        pop(dummy);
    }
}