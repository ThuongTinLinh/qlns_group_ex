#ifndef Project_businessobject_TableUnit_H_//sub class of all table
#define Project_businessobject_TableUnit_H_

#include "../libs/Utility.h"
#include "../ui/IO.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

class TableUnit : public IO{
protected:
    map<string, string> Member;
public:
    TableUnit();
    virtual void ToMapMember() = 0;
    virtual void FromMapMember() = 0;
    virtual TableUnit* ClonePtr() = 0;

    void FromMapIO() override;
    void ToMapIO() override;    
    void SetMapMember(map<string, string> member);
    map<string, string> GetMapMember();
    // void DataIn();
    // void DataOut();
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