#include "IO.h"

IO::IO(){
};
void IO::DataIn(TableData* ptD, TableUnit* ptU){
    TableUnit* unit = ptU->ClonePtr();
    map<string, string> mapMember = unit->GetMapMember();
    map<string, string>::iterator it;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << "enter value for " << it->first << " = ";
        string s = ""; getline(cin, s);
        unit->SetValue(it->first, s);
    }
    ptD->Push(unit);
    cout << "-------------------------------------"<< endl;
}

void IO::DataOut(TableData* ptD){
    // if ptD = null, error because can't denifine TableUnit*. The same TableData/ToString
    map<string, string>::iterator it;
    for(TableUnit* unit: ptD->GetData()){
        map<string, string> mapMember = unit->GetMapMember();
        for (it = mapMember.begin(); it != mapMember.end(); it++){
            cout << "Value for " << it->first << " = "<< it->second << endl;
        }
        cout << "-------------------------------------"<< endl;
    }    
    // cout << ptD -> ToString();
}