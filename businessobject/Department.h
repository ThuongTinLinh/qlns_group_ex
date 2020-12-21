#ifndef Project_businessobject_Department_h_
#define Project_businessobject_Department_h_

#include <string>
using namespace std;

class Department{
private:
    int Id;
    string DName;
    int DNumber;
    long MgrSSN;
    string MgrStartDate;
public :
    Department();
    Department(int id,string dName, int dNumber, long mgrSSN, string mgrStartDate);
};
#endif