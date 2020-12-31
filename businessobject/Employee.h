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
    char Sex;
    int Salary;
    long SuperSNN;
    int DNO;
public:
    Employee();
    Employee(string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno);  
    Employee(vector<string> vt);
    void FromMapMember() override;
    void ToMapMember() override;
    TableUnit *ClonePtr() override;
        
    // string GetFName();
    // void SetFName(string fName);
    // string GetMInit();
    // void SetMInit(string mInit);
    // string GetLName();
    // void SetLName(string lName);
    // long GetSSN();
    // void SetSSN(long ssn);
    // string GetBDate();
    // void SetBDate(string bDate);
    // string GetAddress();
    // void SetAddress(string address);
    // char GetSex();
    // void SetSex(char sex);
    // int GetSalary();
    // void SetSalary(int salary);
    // long GetSuperSNN();
    // void SetSuperSNN(long superSNN);
    // int GetDNO();
    // void SetDNO(int dno);

};

#endif