#include "Department.h"

Department::Department(){};
// input parameters
Department::Department(string dName, int dNumber, long mgrSSN, string mgrStartDate)
{
    DName = dName;                  // Name of department
    DNumber = dNumber;              // Number of department
    MgrSSN = mgrSSN;                // Social security of manafer
    MgrStartDate = mgrStartDate;    // Start date of manager 
};

Department::Department(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void Department::fromMapMember(){
    _dName = Member["DName"];
    _dNumber = stoi(Member["DNumber"]);
    _mgrSSN =stol(Member["MgrSSN"]);
    _mgrStartDate = Member["MgrStartDate"];
}
void Department::toMapMember(){
    Member["DName"] = _dName;
    Member["DNumber"] = to_string(_dNumber);
    Member["MgrSSN"] = to_string(_mgrSSN);
    Member["MgrStartDate"] = _mgrStartDate;
}
TableUnit *Department::ClonePtr(){
    TableUnit *pU = new Department();
    return pU;
}
