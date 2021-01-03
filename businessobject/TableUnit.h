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
    map<string, string> GetMapMember();
    void FromVt(vector<string>);
    void FromStringDecode(string);
    vector<string> ToVt();
    string ToString();
    string ToStringEncode();
    string GetValue(string key);
    void SetValue(string key, string value);
    bool CheckValue(string key, string value); 
};

#endif