#include "Department.h"

Department::Department(){}
// input parameters
Department::Department(string dName, int dNumber, long mgrSSN, string mgrStartDate)
{
    _dName = dName;                  // Name of department
    _dNumber = dNumber;              // Number of department
    _mgrSSN = mgrSSN;                // Social security of manafer
    _mgrStartDate = mgrStartDate;    // Start date of manager 
}
// ========Override========

int Department::fromMapMember(){
    try{
    _dName = _member["DName"];
    _dNumber = stoi(_member["DNumber"]);
    _mgrSSN =stol(_member["MgrSSN"]);
    _mgrStartDate = _member["MgrStartDate"];
    } catch (...) { return 0;};
    return 1;
}
void Department::toMapMember(){
    _member["DName"] = _dName;
    _member["DNumber"] = to_string(_dNumber);
    _member["MgrSSN"] = to_string(_mgrSSN);
    _member["MgrStartDate"] = _mgrStartDate;
}
TableUnit *Department::clonePtr(){
    TableUnit *pU = new Department();
    return pU;
}
