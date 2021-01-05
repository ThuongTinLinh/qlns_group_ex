#ifndef _EMPLOYEES_H_
#define _EMPLOYEES_H_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Employee : public TableUnit{
    string _fName;
    string _mInit;
    string _lName;
    long _ssn;
    string _bDate;
    string _address;
    string _sex;
    int _salary;
    long _superSSN;
    int _dno;
public:
    Employee();
    Employee(string fName, string mInit, string lName, long ssn, string bDate, string address, string sex, int salary, long superSSN, int dno);
    void fromMapMember() override;
    void toMapMember() override;
    TableUnit *clonePtr() override;
};

#endif