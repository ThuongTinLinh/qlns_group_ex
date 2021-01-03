#ifndef Project_businessobject_Project_h_
#define Project_businessobject_Project_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Project : public TableUnit{
    string PName;       // Name of Project
    int PNumber;        // number of Project
    string PLocation;   // Project location
    int DNum;           // dept Location number
public:
    Project();
    Project(string pName, int pNumber, string pLocation, int dNum);
    Project(vector<string> vt);
    void FromMapMember() override;
    void ToMapMember() override;
    TableUnit *ClonePtr() override;
};

#endif // Project_businessobject_Project_h_