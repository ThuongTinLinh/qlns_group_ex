#ifndef Project_businessobject_Dependent_h_
#define Project_businessobject_Dependent_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Dependent : public TableUnit{
    long ESSN;
    string DependentName;
    char Sex;
    string BDate;
    string Relationship;
public:
    Dependent();
    Dependent(long eSSN, string dependentName, char sex, string bDate, string relationship);
    Dependent(vector<string> vt);
    void FromMapMember() override;
    void ToMapMember() override;
    TableUnit *ClonePtr() override;
};
#endif