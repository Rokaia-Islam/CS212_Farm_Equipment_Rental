#ifndef RETURN_STACK_H
#define RETURN_STACK_H

#include <string>

struct ReturnRecord {
    int equipmentId;
    std::string equipmentName;
    std::string renterName;
    std::string returnDate;
    std::string condition;
};

struct StackNode {
    ReturnRecord data;
    StackNode* next;

    StackNode(const ReturnRecord& rec, StackNode* nxt = nullptr)
        : data(rec), next(nxt) {}
};

class ReturnStack {
private:
    StackNode* topNode;
    int currentSize;

public:
    ReturnStack();
    ~ReturnStack();

    bool isEmpty() const;
    int size() const;

    bool push(const ReturnRecord& record);
    bool pop(ReturnRecord& removedRecord);
    bool peek(ReturnRecord& topRecord) const;

    void displayAll() const;
    void clear();
};

#endif // RETURN_STACK_H