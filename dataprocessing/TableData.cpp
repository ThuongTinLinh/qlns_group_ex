#include "TableData.h"

// ========Contructor========
TableData::TableData(){};
TableData::TableData(string filePath, TableUnit* ptU){
    Size = 0;
    Data.resize(0);
    ifstream inFile(filePath);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        TableUnit* unit = ptU->ClonePtr();
        unit->FromStringDecode(buff);
        Data.push_back(unit);
    }
    inFile.close();
};

// ========Ex========
int TableData::DataIn(TableUnit *ptU){
    TableUnit* unit = ptU->ClonePtr();
    unit->DataIn();
    int size = Push(unit);
    return size;
};
int TableData::DataOut(){
    for(TableUnit *unit:Data){
        unit->DataOut();
    }
    return Size;
};
int TableData::GetSize(){
    return Size;
};
string TableData::ToString(){
    string sOut("");
    for(TableUnit* unit:Data){
        sOut = sOut + unit->ToString() + "\n";
    }
    return sOut;
};
int TableData::Push(TableUnit *unit){
    Data.push_back(unit);
    Size++;
    return Size;
};
int TableData::Change(int index, TableUnit *unit){  
    if(index < Data.size()){
        Data[index] = unit;
    } else {
        index = -1;
    };    
    return index;
};
int TableData::Delele(int index){
    if(index < Data.size()){
        Data.erase(Data.begin() + index);
    } else {
        index = -1;
    };
    return index;
};

TableUnit* TableData::GetPtr(int index){
    TableUnit *ptr = nullptr;    
    if(index < Data.size()){
        ptr = Data[index];
    };
    return ptr;
};

TableUnit* TableData::Find(string key, string value){
    for(TableUnit* unit:Data){
        if(unit->CheckValue(key, value)){
            return unit;
            break;
        }
    }
    return nullptr;
};

vector<TableUnit*> TableData::FindList(string key, string value){
    vector<TableUnit*> vts;
    for(TableUnit* unit:Data){
        if(unit->CheckValue(key, value)){
            vts.push_back(unit);
        }
    }
    return vts;
};

vector<TableUnit*> TableData::GetData(){
    return Data;
};