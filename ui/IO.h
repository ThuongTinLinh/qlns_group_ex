#ifndef Project_ui_IO_h_
#define Project_ui_IO_h_

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "..\businessobject\TableUnit.h"
#include "..\businessobject\Employee.h"
#include "..\dataprocessing\TableData.h"
using namespace std;

class IO{
protected:
public:
    IO();
    void DataIn(TableData*);
    void DataIn(TableUnit*);
    void DataOut(TableData*);
    void DataOut(TableUnit*, int);
    void DataEdit(TableData*, string);
    void DataEditById(TableData*);
    void DataDelete(TableData*, string);
    void DataDeleteById(TableData*);
    int SaveData(TableData*, string);
    int LoadData(TableData*, string);
};

#endif // Project_ui_IO_h_