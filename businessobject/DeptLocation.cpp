#include "DeptLocation.h"

// ========Contructor========
DeptLocation::DeptLocation(){
    _dNumber = 0;
    _dLocation = "";
}
DeptLocation::DeptLocation(const int dNumber, const string dLocation){
     _dNumber = dNumber;
    _dLocation = dLocation;
}

// ========Override========

void DeptLocation::fromMapMember(){
     _dNumber = stoi(_member["DNumber"]);
    _dLocation = _member["DLocation"];
}
void DeptLocation::toMapMember(){
    _member["DNumber"] = to_string( _dNumber);
    _member["DLocation"] = _dLocation;
}
TableUnit *DeptLocation::clonePtr(){
    TableUnit *pU = new DeptLocation();
    return pU;
}
