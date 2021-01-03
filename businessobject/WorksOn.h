#ifndef Project_businessobject_WorksOn_h_
#define Project_businessobject_WorksOn_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class WorksOn : public TableUnit{
    long ESSN;
    int PNO;
    double Hours;
public:
    WorksOn();
    WorksOn(long eSSN, int pno, double hours); 
    WorksOn(vector<string> vt);
    void FromMapMember() override;
    void ToMapMember() override;
    TableUnit *ClonePtr() override;
    
};
#endif