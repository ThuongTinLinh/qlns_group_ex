#include "Dependent.h"
#include <string>

Dependent::Dependent(){};

Dependent::Dependent(long eSSN, string dependentName, string sex, string bDate, string relationship)
{
    _eSSN = eSSN;
    _dependentName = dependentName;
    _sex = sex;
    _bDate = bDate;
    _relationship = relationship;
};
// Dependent::Dependent(vector<string> vt){
//     FromVt(vt);
// };

// ========Override========

void Dependent::fromMapMember(){
    _eSSN = stol(Member["ESSN"]);
    _dependentName = Member["DependentName"];
    _sex = Member["Sex"];
     _bDate = Member["BDate"];
   _relationship = Member["Relationship"];
}
void Dependent::toMapMember(){
    Member["ESSN"] = to_string(_eSSN);
    Member["DependentName"] = _dependentName;
    Member["Sex"] = _sex;
    Member["BDate"] = _bDate;
    Member["Relationship"] =_relationship;
}
TableUnit *Dependent::clonePtr(){
    TableUnit *pU = new Dependent();
    return pU;
}
