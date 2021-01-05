#include "WorksOn.h"
#include <string>

WorksOn::WorksOn(){};

WorksOn::WorksOn(long eSSN, int pno, double hours)
{
    _eSSN = eSSN;
    _pno= pno;
    _hours= hours;
};
// WorksOn::WorksOn(vector<string> vt){
//     FromVt(vt);
// };

// ========Override========

void WorksOn::fromMapMember(){
    _eSSN = stol(_member["ESSN"]);
    _pno = stoi(_member["PNO"]);
    _hours = stod(_member["Hours"]);
}
void WorksOn::toMapMember(){
    _member["ESSN"] = to_string(_eSSN);
    _member["PNO"] = to_string(_pno);
    _member["Hours"] = to_string(_hours);
}
TableUnit *WorksOn::clonePtr(){
    TableUnit *pU = new WorksOn();
    return pU;
}
