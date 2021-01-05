#include "DeptLocation.h"

// ========Contructor========
DeptLocation::DeptLocation(){
    _dNumber = 0;
    _dLocation = "";
};
DeptLocation::DeptLocation(const int dNumber, const string dLocation){
     _dNumber = dNumber;
    _dLocation = dLocation;
};
DeptLocation::DeptLocation(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void DeptLocation::fromMapMember(){
     _dNumber = stoi(Member["DNumber"]);
    _dLocation = Member["DLocation"];
}
void DeptLocation::toMapMember(){
    Member["DNumber"] = to_string( _dNumber);
    Member["DLocation"] = _dLocation;
}
TableUnit *DeptLocation::ClonePtr(){
    TableUnit *pU = new DeptLocation();
    return pU;
}
