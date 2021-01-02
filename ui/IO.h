#ifndef Project_ui_IO_h_
#define Project_ui_IO_h_

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "..\businessobject\TableUnit.h"
#include "..\dataprocessing\TableData.h"
using namespace std;

class IO{
protected:
public:
    IO();
    void DataIn(TableData*);
    void DataOut(TableData*);
};

#endif // Project_ui_IO_h_