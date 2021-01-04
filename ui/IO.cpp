#include "IO.h"

IO::IO(){}
void IO::dataIn(TableUnit* pTU){
    map<string, string> mapMember = pTU->GetMapMember(); // Get the map<string, string> store data of TableUnit.
    map<string, string>::iterator it;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << "enter value for " << it->first << " = ";
        string s = ""; getline(cin, s);
        pTU->SetValue(it->first, s);
    }
}
void IO::dataIn(TableData* pTD){
    TableUnit* pTU = pTD->GetTableUnit(); // dynamic memory allocate for a new pointer point to TableUnit.
    dataIn(pTU);
    pTD->Push(pTU);
    cout << "-------------------------------------"<< endl;
}
/** @brief Function that find width of each column to show data in a TableUnit.
 * 
 * @details Get the map<string, string> store data of TableUnit,
 * find the bigger length of string of each pair key - value in this map<string, string>,
 * put this result into a vector<int> in sequence.
 * @param pTU a pointer point to a TableUnit.
 * @return vector<int> store the necessary widths of each column to show data in TableUnit.
*/
vector<int> FindUnitColumnWidth(TableUnit* pTU){
    vector<int> unitWidth;
    unitWidth.resize(pTU->GetMapMember().size(), 0); // set the size of vector<int> equal to number of elements in TableUnit.

    map<string, string>::iterator it;
    map<string, string> mapMember = pTU->GetMapMember();
    int i = 0;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        string name = it->first; string value = it->second;
        unitWidth[i] = (value.length() > name.length()) ? value.length() : name.length();
        i++;
    }
    return unitWidth;
}
/** @brief Function that find width of each column to show datain a TableData.
 * 
 * @details Get the vector<TableUnit*> store data of TableData,
 * get the vector<int> store the necessary widths of each TableUnit,
 * compare and get the vector<int> store max values in these vector<int>.
 * @param pTD apointer point to a TableData.
 * @return vector<int> store the necessary widths of each column to show data in TableData.
*/
vector<int> FindTableColumnWidth(TableData* pTD){
    vector<int> tableWidth;
    // set the size of vector<int> equal to number of elements in TableData.
    tableWidth.resize(pTD->GetTableUnit()->GetMapMember().size(), 0);

    for(TableUnit* unit: pTD->GetData()){
        map<string, string> mapMember = unit->GetMapMember();
        vector<int> unitWidth = FindUnitColumnWidth(unit);
        for (int i = 0; i < tableWidth.size(); i++)
            if (tableWidth[i] < unitWidth[i]) tableWidth[i] = unitWidth[i]; // get vector<int> of max values
    }
    return tableWidth;
        

}
void IO::dataOut(TableData* pTD){
    // if ptD = null, error because can't denifine TableUnit*. The same TableData/ToString
    vector<int> tableWidth = FindTableColumnWidth(pTD);
    int sumWidth = 0;
    for (int i: tableWidth) sumWidth += i + 2;
    map<string, string>::iterator it;
    int j = 0;
    for(TableUnit* unit: pTD->GetData()){
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
    // cout << ptD -> ToString();
}
void IO::dataOut(TableUnit* pTU, int id){
    vector<int> tableWidth = FindUnitColumnWidth(pTU);
    int sumWidth = 0;
    for (int i: tableWidth) sumWidth += i + 2;
    map<string, string>::iterator it;
    map<string, string> mapMember = pTU->GetMapMember();
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

void IO::dataEdit(TableData* pTD, string idName){
    dataOut(pTD);
    vector<TableUnit*> vTU = pTD->GetData();
    
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue);
    for (int i = 0; i < vTU.size(); i++){
        TableUnit* pTU = vTU[i];
        if (pTU->GetValue(idName) == idValue){
            dataOut(pTU, i + 1);
            dataIn(pTU);
            break;
        }
    }
    dataOut(pTD);    
}
void IO::dataEditById(TableData* pTD){
    dataOut(pTD);
    cout << "   Enter Id: ";
    int id = 0; cin >> id; cin.ignore();
    id--;
    TableUnit* pTU = pTD->GetPtr(id);
    dataOut(pTU, id + 1);
    dataIn(pTU);
    dataOut(pTD);
}
void IO::dataDelete(TableData* pTD, string idName){
    dataOut(pTD);
    vector<TableUnit*> vTU = pTD->GetData();
    
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue);
    for (int i = 0; i < vTU.size(); i++){
        TableUnit* pTU = vTU[i];
        if (pTU->GetValue(idName) == idValue){
            dataOut(pTU, i + 1);
            cout << "   Delete this unit?" << endl;
            cout << "   1.Yes." << endl;
            cout << "   2.No."  << endl;
            int select = 0; cin >> select; cin.ignore();
            if (select == 1) pTD->Delele(i);
            break;
        }
    }
    dataOut(pTD);  
}
void IO::dataDeleteById(TableData* pTD){
    dataOut(pTD);
    cout << "   Enter Id: ";
    int id = 0; cin >> id; cin.ignore();
    id--;
    TableUnit* unit = pTD->GetPtr(id);
    dataOut(unit, id + 1);
    cout << "   Delete this unit?" << endl;
    cout << "   1.Yes." << endl;
    cout << "   2.No."  << endl;
    int select = 0; cin >> select; cin.ignore();
    if (select == 1) pTD->Delele(id);
    dataOut(pTD);
}
int IO::saveData(TableData* pTD, string filename){
    string datetime = Utility::getDatetimeString();
    string folderPath = "data/" + filename + "/" + datetime + ".data";
    ofstream outFile(folderPath);
    if(!outFile) return 0;
    for (auto pTU: pTD->GetData()){
        outFile << pTU->ToStringEncode() << endl;
    }
    outFile.close();
    return 1;
}
int IO::loadData(TableData* pTD, string filepath){
    pTD->Resize(0);
    ifstream inFile(filepath);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        string s = buff;
        TableUnit *pTU = pTD->GetTableUnit();
        pTU->FromStringDecode(s);
        pTD->Push(pTU);
    }
    inFile.close();
    return 1;
}