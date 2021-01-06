#ifndef Project_businessobject_TableUnit_H_//sub class of all table
#define Project_businessobject_TableUnit_H_

#include "../libs/Utility.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

class TableUnit{
protected:
    map<string, string> _member;
public:
    TableUnit();
    virtual void toMapMember() = 0;
    virtual int fromMapMember() = 0;
    virtual TableUnit* clonePtr() = 0;
    
    /** @brief Function get from map 
     *  
     *  Function get value from map 
    */
    void setMapMember(map<string, string> member);

    /** @brief Function get value from map
     *  
     *  Function get value from map, 
     *  @return return Member
    */
    map<string, string> getMapMember();

    /** @brief Function convert value of string to value Member[key]
     *  
     *  Function convert value of string to value Member[key]
     * @param vector type string
     * @return success return 1
     *          fail return 0
     */
    int fromVt(vector<string>);

    /** @brief Function covert value of string to type vector
     *  
     *  Function covert value of string to type vector
     * @return success return 1
     *          fail return 0
     */
    int fromStringDecode(string);

    /** @brief Function get value of map put in vector  
     *  
     *  Function get value of map put in vector
     *  @return return vector 
     */
    vector<string> toVt();

    /** @brief Function convert value of map to vector
     *  
     *  Function convert value of map to vector
     *  @return return string
     */
    string toString();

     /** @brief Function get value from map, add string
     *  
     *  Function get value from map, add string
     *  @return return string
     */
    string toStringEncode();

    /** @brief  Fuction get  return value search in map 
     *  
     *@details Fuction get  return value search in map 
     * @return  value of key 
     * 
     */
    string getValue(string key);

    /** @brief Fuction set value use add value for Member[key]
     *  
     * @details Fuction get value use add value for Member[key]
     * @param key string
     * @param value string
     * @return success return 1
     *          fail return 0
     */
    int setValue(string key, string value);

     /** @brief Function checkValue 
     *  
     *  @details Function get value from map, add string
     *  @return true if value of Member[key] equal to value
     */
    bool checkValue(string key, string value); 
};

#endif