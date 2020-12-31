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
    cout << "size Map " << Member.size() << endl;    
    cout << "size MapIO " << MemberIO.size() << endl;
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
        s += Member[it->first] + ", ";
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
        vtOut.push_back(Member[it->first]);
    };
    return vtOut;
};

string TableUnit::ToStringEncode(){
    ToMapMember();
    string sFile = Utility::ToString(ToVt());
    return sFile;
};