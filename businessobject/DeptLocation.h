#ifndef Project_businessobject_DeptLocation_h_
#define Project_businessobject_DeptLocation_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class DeptLocation : public TableUnit{
    int _dNumber;        // number of location
    string _dLocation;   // location name
public:
    DeptLocation();
    DeptLocation(int dNumber, string dLocation);
    void fromMapMember() override;
    void toMapMember() override;
    TableUnit *clonePtr() override;
};

#endif // Project_businessobject_DeptLocation_h_