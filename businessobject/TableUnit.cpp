#include "TableUnit.h"

TableUnit::TableUnit(){
    _member.clear();
};

map<string, string> TableUnit::getMapMember(){
    toMapMember();
    return _member;
}

void TableUnit::setMapMember(map<string, string> member){
    _member.clear();
    _member = member;
    fromMapMember();
};
void TableUnit::fromVt(vector<string> vt){
    toMapMember();
    map<string, string>::iterator it;
    int i=0;
    for (it = _member.begin(); it != _member.end(); it++)
    {
        _member[it->first] = vt[i++];
    };
    fromMapMember();
};
void TableUnit::fromStringDecode(string sCode){    
    vector<string> vt = Utility::fromString(sCode);
    fromVt(vt);
};

string TableUnit::toString(){
    toMapMember();
    map<string, string>::iterator it;
    string s("");
    for (it = _member.begin(); it != _member.end(); it++)
    {
        s += it->second + ", ";
    };
    s.resize(s.size() - 2);
    s = "{" + s +"}";
    return s;
};
vector<string> TableUnit::toVt(){
    toMapMember();
    map<string, string>::iterator it;
    vector<string> vtOut;
    for (it = _member.begin(); it != _member.end(); it++)
    {
        vtOut.push_back(it->second);
    };
    return vtOut;
};

string TableUnit::toStringEncode(){
    toMapMember();
    string sFile = Utility::toString(toVt());
    return sFile;
};

void TableUnit::setValue(string key, string value){
    toMapMember();
    _member[key] = value;
    fromMapMember();
};

string TableUnit::getValue(string key){
    toMapMember();
    // return Member[key];
    // for test
    auto it = _member.find(key);
    string value("");
    if(it == _member.end()){
        value = "N/A";
        cout << "dclmm deo tim thay " << key <<endl;
    } else {
        value = it->second;
    }
    return value;
};

bool TableUnit::checkValue(string key, string value){
    toMapMember();
    return _member[key] == value;
};