#ifndef Project_businessobject_WorksOn_h_
#define Project_businessobject_WorksOn_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class WorksOn : public TableUnit{
    long _eSSN;
    int _pno;
    double _hours;
public:
    WorksOn();
    WorksOn(long eSSN, int pno, double hours);
    int fromMapMember() override;
    void toMapMember() override;
    TableUnit *clonePtr() override;
    
};
#endif