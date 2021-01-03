#include "WorksOn.h"
#include <string>

WorksOn::WorksOn(){};

WorksOn::WorksOn(long eSSN, int pno, double hours)
{
    ESSN = eSSN;
    PNO = pno;
    Hours = hours;
};
WorksOn::WorksOn(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void WorksOn::FromMapMember(){
    ESSN = stol(Member["ESSN"]);
    PNO = stoi(Member["PNO"]);
    Hours = stod(Member["Hours"]);
}
void WorksOn::ToMapMember(){
    Member["ESSN"] = to_string(ESSN);
    Member["PNO"] = to_string(PNO);
    Member["Hours"] = to_string(Hours);
}
TableUnit *WorksOn::ClonePtr(){
    TableUnit *pU = new WorksOn();
    return pU;
}
