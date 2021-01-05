#include "TableUnit.h"

TableUnit::TableUnit(){
    Member.clear();
};

map<string, string> TableUnit::GetMapMember(){
    toMapMember();// Tin xoa
    return Member;
}

void TableUnit::SetMapMember(map<string, string> member){
    Member.clear();
    Member = member;
    fromMapMember();
};
void TableUnit::FromVt(vector<string> vt){
    toMapMember();
    map<string, string>::iterator it;
    int i=0;
    for (it = Member.begin(); it != Member.end(); it++)
    {
        Member[it->first] = vt[i++];
    };
    fromMapMember();
};
void TableUnit::FromStringDecode(string sCode){    
    vector<string> vt = Utility::fromString(sCode);
    FromVt(vt);
};

string TableUnit::ToString(){
    toMapMember();
    map<string, string>::iterator it;
    string s("");
    for (it = Member.begin(); it != Member.end(); it++)
    {
        s += it->second + ", ";
    };
    s.resize(s.size() - 2);
    s = "{" + s +"}";
    return s;
};
vector<string> TableUnit::ToVt(){
    toMapMember();
    map<string, string>::iterator it;
    vector<string> vtOut;
    for (it = Member.begin(); it != Member.end(); it++)
    {
        vtOut.push_back(it->second);
    };
    return vtOut;
};

string TableUnit::ToStringEncode(){
    toMapMember();
    string sFile = Utility::toString(ToVt());
    return sFile;
};

void TableUnit::SetValue(string key, string value){
    toMapMember();
    Member[key] = value;
    fromMapMember();
};

string TableUnit::GetValue(string key){
    toMapMember();
    // return Member[key];
    // for test
    auto it = Member.find(key);
    string value("");
    if(it == Member.end()){
        value = "N/A";
        cout << "dclmm deo tim thay " << key <<endl;
    } else {
        value = it->second;
    }
    return value;
};

bool TableUnit::CheckValue(string key, string value){
    toMapMember();
    return Member[key] == value;
};