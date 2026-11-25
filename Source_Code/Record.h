#ifndef RECORDS_H
#define RECORDS_H
#include <string>
using namespace std;

struct Equipment {
    int id;
    string name;
    string type;
    double dailyRate;
    bool isRented;
    string rentedBy;   // empty when available
};

struct RentalRequest {
    int requestId;
    string customerName;
    int equipmentId;
    int days;
};

struct ReturnRecord {
    int equipmentId;
    string customerName;
};

#endif
