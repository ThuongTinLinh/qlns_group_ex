#include "Department.h"

Department::Department(){};
// input parameters
Department::Department(string dName, int dNumber, int mgrSSN, string mgrStartDate);
{
    DName = dName;                  // Name of department
    DNumber = dNumber;              // Number of department
    MgrSSN = mgrSSN;                // Social security of manafer
    MgrStartDate = mgrStartDate;    // Start date of manager 
}