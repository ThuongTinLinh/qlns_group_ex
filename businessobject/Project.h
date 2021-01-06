#ifndef Project_businessobject_Project_h_
#define Project_businessobject_Project_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class Project : public TableUnit{
    string _pName;       // Name of Project
    int _pNumber;        // number of Project
    string _pLocation;   // Project location
    int _dNum;           // dept Location number
public:
    Project();
    Project(string pName, int pNumber, string pLocation, int dNum);
    
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

#endif // Project_businessobject_Project_h_