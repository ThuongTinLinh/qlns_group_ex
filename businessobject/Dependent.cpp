#include "Dependent.h"
#include <string>

Dependent::Dependent(){}
Dependent::Dependent(int id, long eSSN, string dependentName, char sex, string bDate, string relationship)
{
    Id = id;
    ESSN = eSSN;
    DependentName = dependentName;
    Sex = sex;
    BDate = bDate;
    Relationship = relationship;
}