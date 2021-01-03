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
    DataOut(ptD);
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
void IO::DataEdit(TableData* ptD, string idName){
    DataOut(ptD);
    TableUnit* unit = ptD->GetTableUnit();
    vector<TableUnit*> vtU = ptD->GetData();
    
    TableData* tDTemp = new TableData(unit);
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue);
    for (int i = 0; i < vtU.size(); i++){
        TableUnit* tU = vtU[i];
        if (tU->GetValue(idName) == idValue){
            tDTemp->Push(tU);
            DataOut(tDTemp);

            map<string, string> mapMember = unit->GetMapMember();
            map<string, string>::iterator it;
            for (it = mapMember.begin(); it != mapMember.end(); it++){
                cout << "enter value for " << it->first << " = ";
                string newValue = ""; getline(cin, newValue);
                unit->SetValue(it->first, newValue);
            }
            ptD->Change(i, unit);
            break;
        }
    }
    DataOut(ptD);    
}
void IO::DataEditById(TableData* ptD){
    DataOut(ptD);
    cout << "   Enter Id: ";
    int Id = 0; cin >> Id; cin.ignore();
    Id--;
    TableUnit* unit = ptD->GetPtr(Id);
    TableData* tDTemp = new TableData(ptD->GetTableUnit());
    tDTemp->Push(unit);
    DataOut(tDTemp);
    map<string, string> mapMember = unit->GetMapMember();
    map<string, string>::iterator it;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << "enter value for " << it->first << " = ";
        string newValue = ""; getline(cin, newValue);
        unit->SetValue(it->first, newValue);
    }
    ptD->Change(Id, unit);
    DataOut(ptD);
}
void IO::DataDelete(TableData* ptD, string idName){
    DataOut(ptD);
    TableUnit* unit = ptD->GetTableUnit();
    vector<TableUnit*> vtU = ptD->GetData();
    
    TableData* tDTemp = new TableData(unit);
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue);
    for (int i = 0; i < vtU.size(); i++){
        TableUnit* tU = vtU[i];
        if (tU->GetValue(idName) == idValue){
            tDTemp->Push(tU);
            DataOut(tDTemp);
            cout << "   Delete this unit?" << endl;
            cout << "   1.Yes." << endl;
            cout << "   2.No."  << endl;
            int select = 0; cin >> select; cin.ignore();
            if (select == 1) ptD->Delele(i);
            break;
        }
    }
    DataOut(ptD);  
}
void IO::DataDeleteById(TableData* ptD){
    DataOut(ptD);
    cout << "   Enter Id: ";
    int Id = 0; cin >> Id; cin.ignore();
    Id--;
    TableUnit* unit = ptD->GetPtr(Id);
    TableData* tDTemp = new TableData(ptD->GetTableUnit());
    tDTemp->Push(unit);
    DataOut(tDTemp);
    cout << "   Delete this unit?" << endl;
    cout << "   1.Yes." << endl;
    cout << "   2.No."  << endl;
    int select = 0; cin >> select; cin.ignore();
    if (select == 1) ptD->Delele(Id);
    DataOut(ptD);
}