#ifndef Project_businessobject_Department_h_
#define Project_businessobject_Department_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Department : public TableUnit{
private:
    string _dName;
    int _dNumber;
    long _mgrSSN;
    string _mgrStartDate;
public :
    Department();
    Department(string dName, int dNumber, long mgrSSN, string mgrStartDate);

    /** @brief Function update attribute from the array _member
     *  
     *@details  Function update attribute from the array _member
    */
    void fromMapMember() override;

    /** @brief Function save attribute in array member
     * 
     *@details Function save attribute in array member
     *
    */
    void toMapMember() override;
    
    /** @brief Function initialize a new memory 
     * 
     *@details Function initialize a new memory 
     *
    */
    TableUnit *clonePtr() override;
};
#endif