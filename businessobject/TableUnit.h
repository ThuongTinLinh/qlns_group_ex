#ifndef Project_businessobject_TableUnit_H_//sub class of all table
#define Project_businessobject_TableUnit_H_

#include "../libs/Utility.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

class TableUnit{
protected:
    map<string, string> Member;
public:
    TableUnit();
    virtual void ToMapMember() = 0;
    virtual void FromMapMember() = 0;
    virtual TableUnit* ClonePtr() = 0;

    void SetMapMember(map<string, string> member);

    /** @brief Function get value from map
     *  
     *  Function get value from map, 
     *  @return return Member
    */
    map<string, string> GetMapMember();

    /** @brief Function 
     *  
     *  Function get value from map, 
     *  @return return Member
     */
    void FromVt(vector<string>);

    /** @brief Function 
     *  
     *  Function get value from map, 
     *  @return return Member
     */
    void FromStringDecode(string);

    /** @brief Function get value of map put in vector  
     *  
     *  Function get value of map put in vector
     *  @return return vector
     */
    vector<string> ToVt();

    /** @brief Function get value from map, add string
     *  
     *  Function get value from map, add string
     *  @return return string
     */
    string ToString();

    string ToStringEncode();

    /** @brief 
     *  
     *  Function get value from map, add string
     *  @return return value type string
     */

    string GetValue(string key);

    /** @brief Fuction Set 
     *  
     *  Function get value from map, add string
     *  @return return value type string
     */
    void SetValue(string key, string value);

     /** @brief Function checkValue 
     *  
     *  Function get value from map, add string
     *  @return return string
     */
    bool CheckValue(string key, string value); 
};

#endif