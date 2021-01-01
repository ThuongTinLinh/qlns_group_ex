#ifndef _EMPLOYEES_H_
#define _EMPLOYEES_H_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Employee : public TableUnit{
    string FName;
    string MInit;
    string LName;
    long SSN;
    string BDate;
    string Address;
    string Sex;
    int Salary;
    long SuperSSN;
    int DNO;
public:
    Employee();
    Employee(string fName, string mInit, string lName, long ssn, string bDate, string address, string sex, int salary, long superSSN, int dno);  
    Employee(vector<string> vt);
    void FromMapMember() override;
    void ToMapMember() override;
    TableUnit *ClonePtr() override;
};

#endif