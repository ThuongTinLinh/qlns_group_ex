#include "IO.h"
#include <algorithm>

IO::IO(){
};
void IO::DataIn(TableData* ptD){
    TableUnit* unit = ptD->GetTableUnit();
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
vector<int> FindColumnWidth(TableData* ptD){
    vector<int> tableWidth;
    tableWidth.resize(ptD->GetTableUnit()->GetMapMember().size(), 0);

    map<string, string>::iterator it;
    for(TableUnit* unit: ptD->GetData()){
        map<string, string> mapMember = unit->GetMapMember();
        int i = 0;
        for (it = mapMember.begin(); it != mapMember.end(); it++){
            string name = it->first; string value = it->second;
            if(value.length() > name.length() && value.length() > tableWidth[i]) {
                tableWidth[i] = value.length();
            }
            else if (name.length() > tableWidth[i]){
                tableWidth[i] = name.length();
            }
            i++;
        }
    }
    return tableWidth;
    
}
void IO::DataOut(TableData* ptD){
    // if ptD = null, error because can't denifine TableUnit*. The same TableData/ToString
    vector<int> tableWidth = FindColumnWidth(ptD);
    int sumWidth = 0;
    for (int i: tableWidth) sumWidth += i + 2;
    map<string, string>::iterator it;
    int j = 0;
    for(TableUnit* unit: ptD->GetData()){
        map<string, string> mapMember = unit->GetMapMember();
        if (j ==0) {
            int i = 0;
            cout << endl << string(sumWidth + 5/*Id*/, '-') << endl;
            cout << setw(5) << left << "Id";
            for (it = mapMember.begin(); it != mapMember.end(); it++){
                cout << setw(tableWidth[i] + 2) << left << it->first;
                i++;
            }
            cout << endl << string(sumWidth + 5/*Id*/, '=') << endl;
        }
        int i = 0;
        cout << setw(5) << left << j+1;
        for (it = mapMember.begin(); it != mapMember.end(); it++){
        //cout << "Value for " << it->first << " = "<< it->second << endl;
            cout << setw(tableWidth[i] + 2) << left << ((it->second == "-1") ? "null" : it->second);
            i++;
        }
        cout << endl << string(sumWidth + 5/*Id*/, '-') << endl;
        j++;
    }
    cout << endl << endl;   
    // cout << ptD -> ToString();
}