#include "WorksOn.h"
#include <string>

WorksOn::WorksOn(){};

WorksOn::WorksOn(long eSSN, int pno, double hours)
{
    _eSSN = eSSN;
    _pno= pno;
    _hours= hours;
};
WorksOn::WorksOn(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void WorksOn::fromMapMember(){
    _eSSN = stol(Member["ESSN"]);
    _pno = stoi(Member["PNO"]);
    _hours = stod(Member["Hours"]);
}
void WorksOn::toMapMember(){
    Member["ESSN"] = to_string(_eSSN);
    Member["PNO"] = to_string(_pno);
    Member["Hours"] = to_string(_hours);
}
TableUnit *WorksOn::clonePtr(){
    TableUnit *pU = new WorksOn();
    return pU;
}
