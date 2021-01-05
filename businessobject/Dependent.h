#ifndef Project_businessobject_Dependent_h_
#define Project_businessobject_Dependent_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Dependent : public TableUnit{
    long _eSSN;
    string _dependentName;
    string _sex;
    string _bDate;
    string _relationship;
public:
    Dependent();
    Dependent(long eSSN, string dependentName, string sex, string bDate, string relationship);
    void fromMapMember() override;
    void toMapMember() override;
    TableUnit *clonePtr() override;
};
#endif