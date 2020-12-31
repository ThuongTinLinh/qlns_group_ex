#include "TableUnit.h"

TableUnit::TableUnit(){
    Member.clear();
};

map<string, string> TableUnit::GetMapMember(){
    ToMapMember();
    return Member;
}

void TableUnit::SetMapMember(map<string, string> member){
    Member.clear();
    Member = member;
    FromMapMember();
};

void TableUnit::ToMapIO(){
    ToMapMember();
    MemberIO.clear();
    MemberIO = Member;
};

void TableUnit::FromMapIO(){
    Member.clear();
    Member = MemberIO;
    FromMapMember();
};

void TableUnit::FromVt(vector<string> vt){
    ToMapMember();
    map<string, string>::iterator it;
    int i=0;
    for (it = Member.begin(); it != Member.end(); it++)
    {
        Member[it->first] = vt[i++];
    };
    FromMapMember();
};
void TableUnit::FromStringDecode(string sCode){    
    vector<string> vt = Utility::FromString(sCode);
    FromVt(vt);
};

string TableUnit::ToString(){
    ToMapMember();
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
    ToMapMember();
    map<string, string>::iterator it;
    vector<string> vtOut;
    for (it = Member.begin(); it != Member.end(); it++)
    {
        vtOut.push_back(it->second);
    };
    return vtOut;
};

string TableUnit::ToStringEncode(){
    ToMapMember();
    string sFile = Utility::ToString(ToVt());
    return sFile;
};

string TableUnit::GetValue(string key){
    ToMapMember();
    auto it = Member.find(key);
    string value("");
    if(it == Member.end()){
        value = "N/A";
        cout << "dclmm deo tim thay " << key<<endl;
    } else {
        value = it->second;
    }
    return value;
};

bool TableUnit::CheckValue(string key, string value){
    ToMapMember();
    auto it = Member.find(key);
    bool f;
    if(it == Member.end()){
        f = false;
    } else if(value != it->second) {
        f = false;
    } else {        
        f = true;
    }    
    return f;
};