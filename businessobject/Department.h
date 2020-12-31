#ifndef Project_businessobject_Department_h_
#define Project_businessobject_Department_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Department : public TableUnit{
private:
    string DName;
    int DNumber;
    long MgrSSN;
    string MgrStartDate;
public :
    Department();
    Department(string dName, int dNumber, long mgrSSN, string mgrStartDate);
    Department(vector<string> vt);
    void FromMapMember() override;
    void ToMapMember() override;
    TableUnit *ClonePtr() override;
};
#endif