#include "DeptLocation.h"

// ========Contructor========
DeptLocation::DeptLocation(){
    DNumber = 0;
    DLocation = "";
};
DeptLocation::DeptLocation(const int dNumber, const string dLocation){
    DNumber = dNumber;
    DLocation = dLocation;
};
DeptLocation::DeptLocation(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void DeptLocation::FromMapMember(){
    DNumber = stoi(Member["DNumber"]);
    DLocation = Member["DLocation"];
}
void DeptLocation::ToMapMember(){
    Member["DNumber"] = to_string(DNumber);
    Member["DLocation"] = DLocation;
}
TableUnit *DeptLocation::ClonePtr(){
    TableUnit *pU = new DeptLocation();
    return pU;
};
