#ifndef Project_businessobject_Project_h_
#define Project_businessobject_Project_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Project : public TableUnit{
    string _pName;       // Name of Project
    int _pNumber;        // number of Project
    string _pLocation;   // Project location
    int _dNum;           // dept Location number
public:
    Project();
    Project(string pName, int pNumber, string pLocation, int dNum);
    Project(vector<string> vt);
    void fromMapMember() override;
    void toMapMember() override;
    TableUnit *ClonePtr() override;
};

#endif // Project_businessobject_Project_h_