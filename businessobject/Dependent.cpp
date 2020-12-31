#include "Dependent.h"
#include <string>

Dependent::Dependent(){};

Dependent::Dependent(long eSSN, string dependentName, char sex, string bDate, string relationship)
{
    ESSN = eSSN;
    DependentName = dependentName;
    Sex = sex;
    BDate = bDate;
    Relationship = relationship;
};
Dependent::Dependent(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void Dependent::FromMapMember(){
    ESSN = stol(Member["ESSN"]);
    DependentName = Member["DependentName"];
    Sex = Member["Sex"][0];
    BDate = Member["BDate"];
    Relationship = Member["Relationship"];
}
void Dependent::ToMapMember(){
    Member["ESSN"] = to_string(ESSN);
    Member["DependentName"] = DependentName;
    Member["Sex"] = to_string(Sex);
    Member["BDate"] = BDate;
    Member["Relationship"] = Relationship;
}
TableUnit *Dependent::ClonePtr(){
    TableUnit *pU = new Dependent();
    return pU;
};
