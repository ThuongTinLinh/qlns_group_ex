#ifndef Project_businessobject_DeptLocation_h_
#define Project_businessobject_DeptLocation_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class DeptLocation : public TableUnit{
    int DNumber;        // number of location
    string DLocation;   // location name
public:
    DeptLocation();
    DeptLocation(int dNumber, string dLocation);
    DeptLocation(vector<string> vt);
    void FromMapMember() override;
    void ToMapMember() override;
    TableUnit *ClonePtr() override;
};

#endif // Project_businessobject_DeptLocation_h_