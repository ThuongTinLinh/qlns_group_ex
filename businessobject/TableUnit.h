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
    virtual void toMapMember() = 0;
    virtual void fromMapMember() = 0;
    virtual TableUnit* ClonePtr() = 0;
    
    /** @brief Function get from map 
     *  
     *  Function get value from map 
    */
    void SetMapMember(map<string, string> member);

    /** @brief Function get value from map
     *  
     *  Function get value from map, 
     *  @return return Member
    */
    map<string, string> GetMapMember();

    /** @brief Function convert value of string to value Member[key]
     *  
     *  Function convert value of string to value Member[key]
     * @param vector type string
     */
    void FromVt(vector<string>);

    /** @brief Function covert value of string to type vector
     *  
     *  Function covert value of string to type vector
     *  @return return vector
     */
    void FromStringDecode(string);

    /** @brief Function get value of map put in vector  
     *  
     *  Function get value of map put in vector
     *  @return return vector 
     */
    vector<string> ToVt();

    /** @brief Function convert value of map to vector
     *  
     *  Function convert value of map to vector
     *  @return return string
     */
    string ToString();

     /** @brief Function get value from map, add string
     *  
     *  Function get value from map, add string
     *  @return return string
     */
    string ToStringEncode();

    /** @brief  Fuction convert object to encoded string 
     *  
     *@details  Fuction convert object to encoded string 
     * @return return value type string
     */
    string GetValue(string key);

    /** @brief Fuction set value use add value for Member[key]
     *  
     * @details Fuction get value use add value for Member[key]
     * @param key string
     * @param value string 
     */
    void SetValue(string key, string value);

     /** @brief Function checkValue 
     *  
     *  @details Function get value from map, add string
     *  @return true if value of Member[key] equal to value
     */
    bool CheckValue(string key, string value); 
};

#endif