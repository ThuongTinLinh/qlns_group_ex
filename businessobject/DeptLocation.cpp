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

int DeptLocation::fromMapMember(){
    try{
     _dNumber = stoi(_member["DNumber"]);
    _dLocation = _member["DLocation"];
    } catch (...) { return 0;};
    return 1;
}
void DeptLocation::toMapMember(){
    _member["DNumber"] = to_string( _dNumber);
    _member["DLocation"] = _dLocation;
}
TableUnit *DeptLocation::clonePtr(){
    TableUnit *pU = new DeptLocation();
    return pU;
}
