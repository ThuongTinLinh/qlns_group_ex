#ifndef Project_ui_IO_h_
#define Project_ui_IO_h_

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class IO{
protected:
    map<string, string> MemberIO;
public:
    IO();
    virtual void ToMapIO() = 0;
    virtual void FromMapIO() = 0;
    void DataIn();
    void DataOut();
};

#endif // Project_ui_IO_h_