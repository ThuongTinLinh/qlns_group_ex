#ifndef Project_businessobject_Project_h_
#define Project_businessobject_Project_h_

#include <iostream>
#include <string>
using namespace std;

class Project{
    int Id;             // id of Project
    string PName;       // Name of Project
    int PNumber;        // number of Project
    string PLocation;   // Project location
    int DNum;           // dept Location number
public:
    Project();
    Project(int id, string pName, int pNumber, string pLocation, int dNum);
};

#endif // Project_businessobject_Project_h_