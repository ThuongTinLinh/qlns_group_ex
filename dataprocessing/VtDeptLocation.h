#ifndef Project_dataprocessing_VtDeptLocation_h_
#define Project_dataprocessing_VtDeptLocation_h_

#include "../businessobject/DeptLocation.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class VtDeptLocation{
    vector<DeptLocation> VtDL;             // id of location
public:
    vtDeptLocation();
    int addElement(DeptLocation dL);
    int changeElement(int id, int dNumber, string dLocation);
    int deleleElement(int id);
    DeptLocation readElement(int id);
    int erase();
};

#endif // Project_dataprocessing_VtDeptLocation_h_