#ifndef Project_businessobject_DeptLocation_h_
#define Project_businessobject_DeptLocation_h_

#include <iostream>
#include <string>
#include <vector>
#include "TableUnit.h"
using namespace std;

class DeptLocation : public TableUnit{
    int _dNumber;        // number of location
    string _dLocation;   // location name
public:
    DeptLocation();
    DeptLocation(int dNumber, string dLocation);

    /** @brief Function update attribute from the array _member
     *  
     *@details  Function update attribute from the array _member
    */
    int fromMapMember() override;

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

#endif // Project_businessobject_DeptLocation_h_