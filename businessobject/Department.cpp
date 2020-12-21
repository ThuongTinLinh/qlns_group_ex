#include "Department.h"

Department::Department(){};
// input parameters
Department::Department(int id,string dName, int dNumber, long mgrSSN, string mgrStartDate)
{
    Id =id;
    DName = dName;                  // Name of department
    DNumber = dNumber;              // Number of department
    MgrSSN = mgrSSN;                // Social security of manafer
    MgrStartDate = mgrStartDate;    // Start date of manager 
}