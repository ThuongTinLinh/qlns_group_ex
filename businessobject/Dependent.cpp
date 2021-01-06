#include "Dependent.h"
#include <string>

Dependent::Dependent(){}

Dependent::Dependent(long eSSN, string dependentName, string sex, string bDate, string relationship)
{
    _eSSN = eSSN;
    _dependentName = dependentName;
    _sex = sex;
    _bDate = bDate;
    _relationship = relationship;
}
// ========Override========

void Dependent::fromMapMember(){
    _eSSN = stol(_member["ESSN"]);
    _dependentName = _member["DependentName"];
    _sex = _member["Sex"];
     _bDate = _member["BDate"];
   _relationship = _member["Relationship"];
}
void Dependent::toMapMember(){
    _member["ESSN"] = to_string(_eSSN);
    _member["DependentName"] = _dependentName;
    _member["Sex"] = _sex;
    _member["BDate"] = _bDate;
    _member["Relationship"] =_relationship;
}
TableUnit *Dependent::clonePtr(){
    TableUnit *pU = new Dependent();
    return pU;
}
