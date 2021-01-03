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

void Department::FromMapMember(){
    DName = Member["DName"];
    DNumber = stoi(Member["DNumber"]);
    MgrSSN =stol(Member["MgrSSN"]);
    MgrStartDate = Member["MgrStartDate"];
}
void Department::ToMapMember(){
    Member["DName"] = DName;
    Member["DNumber"] = to_string(DNumber);
    Member["MgrSSN"] = to_string(MgrSSN);
    Member["MgrStartDate"] = MgrStartDate;
}
TableUnit *Department::ClonePtr(){
    TableUnit *pU = new Department();
    return pU;
}
