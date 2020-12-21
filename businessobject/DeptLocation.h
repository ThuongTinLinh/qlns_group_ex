#ifndef Project_businessobject_DeptLocation_h_
#define Project_businessobject_DeptLocation_h_

#include <iostream>
#include <string>
using namespace std;

class DeptLocation{
    int Id;             // id of location
    int DNumber;        // number of location
    string DLocation;   // location name
public:
    DeptLocation();
    DeptLocation(int id, int dNumber, string dLocation);
};

#endif // Project_businessobject_DeptLocation_h_