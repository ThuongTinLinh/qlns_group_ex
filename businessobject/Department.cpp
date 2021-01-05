#include "Department.h"

Department::Department(){};
// input parameters
Department::Department(string dName, int dNumber, long mgrSSN, string mgrStartDate)
{
    _dName = dName;                  // Name of department
    _dNumber = dNumber;              // Number of department
    _mgrSSN = mgrSSN;                // Social security of manafer
    _mgrStartDate = mgrStartDate;    // Start date of manager 
};

// Department::Department(vector<string> vt){
//     fromVt(vt);
// };

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
TableUnit *Department::clonePtr(){
    TableUnit *pU = new Department();
    return pU;
}
