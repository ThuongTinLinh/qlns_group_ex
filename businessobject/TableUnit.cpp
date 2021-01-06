#include "TableUnit.h"

TableUnit::TableUnit(){
    _member.clear();
}

map<string, string> TableUnit::getMapMember(){
    toMapMember();
    return _member;
}

void TableUnit::setMapMember(map<string, string> member){
    _member.clear();
    _member = member;
    fromMapMember();
}
int TableUnit::fromVt(vector<string> vt){
    toMapMember();
    map<string, string>::iterator it;
    int i=0;
    for (it = _member.begin(); it != _member.end(); it++)
    {   
        _member[it->first] = vt[i++];
    }
    int check = fromMapMember();
    return check;
}
int TableUnit::fromStringDecode(string sCode){    
    vector<string> vt = Utility::fromString(sCode);
    int check = fromVt(vt);
    return check;
}

string TableUnit::toString(){
    toMapMember();
    map<string, string>::iterator it;
    string s("");
    for (it = _member.begin(); it != _member.end(); it++)
    {
        s += it->second + ", ";
    }
    s.resize(s.size() - 2);
    s = "{" + s +"}";
    return s;
}
vector<string> TableUnit::toVt(){
    toMapMember();
    map<string, string>::iterator it;
    vector<string> vtOut;
    for (it = _member.begin(); it != _member.end(); it++)
    {
        vtOut.push_back(it->second);
    }
    return vtOut;
}

string TableUnit::toStringEncode(){
    toMapMember();
    string sFile = Utility::toString(toVt());
    return sFile;
}

int TableUnit::setValue(string key, string value){
    toMapMember();
    _member[key] = value;
    int check = fromMapMember();
    return check;
}

string TableUnit::getValue(string key){
    toMapMember();
    return _member[key];
}

bool TableUnit::checkValue(string key, string value){
    toMapMember();
    return _member[key] == value;
}