#ifndef Project_dataprocessing_TableData_h_
#define Project_dataprocessing_TableData_h_

#include "../businessobject/TableUnit.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class TableData{
    vector<TableUnit*> Data;
    int Size;
public:
    TableData();
    TableData(string filePath, TableUnit* ptU);

    int DataIn(TableUnit *ptU);
    int DataOut();
    int DataOut(int index);
    int GetSize();
    string ToString();
    int ToJson(string filePath);

    int Push(TableUnit *ptU);
    int Change(int index, TableUnit *ptU);
    int Delele(int index);
    TableUnit* Find(string key, string value);
    vector<TableUnit*> FindList(string key, string value);
    TableUnit* GetPtr(int index);
    vector<TableUnit*> GetData();
};

#endif // Project_dataprocessing_TableData_h_