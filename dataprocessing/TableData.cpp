#include "TableData.h"

// ========Contructor========
TableData::TableData(TableUnit* ptU){
    _tableUnit = ptU;
};
TableData::TableData(string filePath, TableUnit* ptU){
    _size = 0;
    _data.resize(0);
    ifstream inFile(filePath);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        TableUnit* unit = getTableUnit();
        unit->fromStringDecode(buff);
    _data.push_back(unit);
    }
    inFile.close();
}

// ========Ex========
int TableData::getSize(){
    return _size;
}
void TableData::resize(int n){
    _data.resize(n);
}
string TableData::toString(){
    string sOut("");
    for(TableUnit* unit:_data){
        sOut = sOut + unit->ToString() + "\n";
    }
    return sOut;
}
TableUnit* TableData::getTableUnit(){
    TableUnit* ptU = _tableUnit->ClonePtr();
    return ptU;
}
int TableData::push(TableUnit *unit){
    _data.push_back(unit);
    _size++;
    return _ssize;
}
int TableData::change(int index, TableUnit *unit){  
    if(index <_data.size()){
        _data[index] = unit;
    } else {
        index = -1;
    };    
    return index;
};
int TableData::delele(int index){
    if(index <_data.size()){
        _data.erase_data.begin() + index);
    } else {
        index = -1;
    };
    return index;
};

TableUnit* TableData::getPtr(int index){
    TableUnit *ptr = nullptr;    
    if(index <_data.size()){
        ptr = _data[index];
    };
    return ptr;
};

TableUnit* TableData::find(string key, string value){
    for(TableUnit* unit:_data){
        if(unit->CheckValue(key, value)){
            return unit;
            break;
        }
    }
    return nullptr;
};

vector<TableUnit*> TableData::findList(string key, string value){
    vector<TableUnit*> vts;
    for(TableUnit* unit:_data){
        if(unit->CheckValue(key, value)){
            vts.push_back(unit);
        }
    }
    return vts;
};

vector<TableUnit*> TableData::getData(){
    return _data;
};