#ifndef Project_businessobject_Department_h_
#define Project_businessobject_Department_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Department : public TableUnit{
private:
    string _dName;
    int _dNumber;
    long _mgrSSN;
    string _mgrStartDate;
public :
    Department();
    Department(string dName, int dNumber, long mgrSSN, string mgrStartDate);
    Department(vector<string> vt);
    void fromMapMember() override;
    void toMapMember() override;
    TableUnit *ClonePtr() override;
};
#endif