#include "IO.h"
#include <iomanip>
#include <ctime>
#include <sstream>

IO::IO(){}
string datetimeString();
void IO::DataIn(TableUnit* ptU){
    map<string, string> mapMember = ptU->GetMapMember();
    map<string, string>::iterator it;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << "enter value for " << it->first << " = ";
        string s = ""; getline(cin, s);
        ptU->SetValue(it->first, s);
    }
}
void IO::DataIn(TableData* ptD){
    TableUnit* unit = ptD->GetTableUnit();
    DataIn(unit);
    ptD->Push(unit);
    cout << "-------------------------------------"<< endl;
}
vector<int> FindUnitColumnWidth(TableUnit* ptU){
    vector<int> unitWidth;
    unitWidth.resize(ptU->GetMapMember().size(), 0);

    map<string, string>::iterator it;
    map<string, string> mapMember = ptU->GetMapMember();
    int i = 0;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        string name = it->first; string value = it->second;
        unitWidth[i] = (value.length() > name.length()) ? value.length() : name.length();
        i++;
    }
    return unitWidth;
}
vector<int> FindTableColumnWidth(TableData* ptD){
    vector<int> tableWidth;
    tableWidth.resize(ptD->GetTableUnit()->GetMapMember().size(), 0);

    for(TableUnit* unit: ptD->GetData()){
        map<string, string> mapMember = unit->GetMapMember();
        vector<int> unitWidth = FindUnitColumnWidth(unit);
        for (int i = 0; i < tableWidth.size(); i++)
            if (tableWidth[i] < unitWidth[i]) tableWidth[i] = unitWidth[i];
    }
    return tableWidth;
        

}
void IO::DataOut(TableData* ptD){
    // if ptD = null, error because can't denifine TableUnit*. The same TableData/ToString
    vector<int> tableWidth = FindTableColumnWidth(ptD);
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
            cout << setw(tableWidth[i] + 2) << left << ((it->second == "-1") ? "null" : it->second);
            i++;
        }
        cout << endl << string(sumWidth + 5/*Id*/, '-') << endl;
        j++;
    }
    cout << endl << endl;
    cout << datetimeString() <<endl;
    // cout << ptD -> ToString();
}
void IO::DataOut(TableUnit* ptU, int id){
    vector<int> tableWidth = FindUnitColumnWidth(ptU);
    int sumWidth = 0;
    for (int i: tableWidth) sumWidth += i + 2;
    map<string, string>::iterator it;
    map<string, string> mapMember = ptU->GetMapMember();
    cout << endl << string(sumWidth + 5/*Id*/, '-') << endl;
    cout << setw(5) << left << "Id";
    int i = 0; // iterator for headline
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << setw(tableWidth[i] + 2) << left << it->first;
        i++;
    }
    cout << endl << string(sumWidth + 5/*Id*/, '=') << endl;
    i = 0; // iterator for value
    cout << setw(5) << left << id;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << setw(tableWidth[i] + 2) << left << ((it->second == "-1") ? "null" : it->second);
        i++;
    }
    cout << endl << string(sumWidth + 5/*Id*/, '-') << endl;
}

void IO::DataEdit(TableData* ptD, string idName){
    DataOut(ptD);
    vector<TableUnit*> vtU = ptD->GetData();
    
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue);
    for (int i = 0; i < vtU.size(); i++){
        TableUnit* tU = vtU[i];
        if (tU->GetValue(idName) == idValue){
            DataOut(tU, i + 1);
            DataIn(tU);
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
    DataOut(unit, Id + 1);
    DataIn(unit);
    DataOut(ptD);
}
void IO::DataDelete(TableData* ptD, string idName){
    DataOut(ptD);
    vector<TableUnit*> vtU = ptD->GetData();
    
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue);
    for (int i = 0; i < vtU.size(); i++){
        TableUnit* tU = vtU[i];
        if (tU->GetValue(idName) == idValue){
            DataOut(tU, i + 1);
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
    DataOut(unit, Id + 1);
    cout << "   Delete this unit?" << endl;
    cout << "   1.Yes." << endl;
    cout << "   2.No."  << endl;
    int select = 0; cin >> select; cin.ignore();
    if (select == 1) ptD->Delele(Id);
    DataOut(ptD);
}
string datetimeString(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y_%H-%M-%S");
    auto str = oss.str();
    return str;
}
int IO::SaveData(TableData* ptD, string filename){
    string datetime = datetimeString();
    string folderPath = "data/" + filename + "/" + datetime + ".data";
    ofstream outFile(folderPath);
    if(!outFile) return 0;
    for (auto tU: ptD->GetData()){
        outFile << tU->ToStringEncode() << endl;
    }
    outFile.close();
    return 1;
}
int IO::LoadData(TableData* ptD, string filename){
    ptD->Resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        string s = buff;
        TableUnit *ptU = ptD->GetTableUnit();
        ptU->FromStringDecode(s);
        ptD->Push(ptU);
    }
    inFile.close();
    return 1;
}