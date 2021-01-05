#include "IO.h"

IO::IO(){}
void IO::dataIn(TableUnit* pTU){
    map<string, string> mapMember = pTU->getMapMember(); // Get the map<string, string> store data of TableUnit.
    map<string, string>::iterator it;
    
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << "enter value for " << it->first << " = ";
        string s = ""; getline(cin, s); //cin.ignore();
        pTU->setValue(it->first, s);
    }
}
void IO::dataIn(TableData* pTD){
    TableUnit* pTU = pTD->getTableUnit(); // dynamic memory allocate for a new pointer point to TableUnit.
    dataIn(pTU);
    pTD->push(pTU);
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
vector<int> findUnitColumnWidth(TableUnit* pTU){
    vector<int> unitWidth;
    unitWidth.resize(pTU->getMapMember().size(), 0); // set the size of vector<int> equal to number of elements in TableUnit.

    map<string, string>::iterator it;
    map<string, string> mapMember = pTU->getMapMember();
    int i = 0;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        string name = it->first; string value = it->second;
        unitWidth[i] = (value.length() > name.length()) ? value.length() : name.length();
        i++;
    }
    return unitWidth;
}
/** @brief Function that find width of each column to show data in a TableData.
 * 
 * @details Get the vector<TableUnit*> store data of TableData,
 * get the vector<int> store the necessary widths of each TableUnit,
 * compare and get the vector<int> store max values in these vector<int>.
 * @param pTD apointer point to a TableData.
 * @return vector<int> store the necessary widths of each column to show data in TableData.
*/
vector<int> findTableColumnWidth(TableData* pTD){
    vector<int> tableWidth;
    // set the size of vector<int> equal to number of elements in TableData.
    tableWidth.resize(pTD->getTableUnit()->getMapMember().size(), 0);

    for(TableUnit* unit: pTD->getData()){  // get vector<int> of max values
        map<string, string> mapMember = unit->getMapMember();
        vector<int> unitWidth = findUnitColumnWidth(unit);
        for (int i = 0; i < tableWidth.size(); i++)
            if (tableWidth[i] < unitWidth[i]) tableWidth[i] = unitWidth[i];
    }
    return tableWidth;
        

}
void IO::dataOut(TableData* pTD){
    // if ptD = null, error because can't denifine TableUnit*. The same TableData/ToString
    vector<int> tableWidth = findTableColumnWidth(pTD); // get vetor<int> contain column width
    int sumWidth = 0; // total width of Table
    for (int i: tableWidth) sumWidth += i + 2 /*distance between 2 column*/;
    map<string, string>::iterator it;
    int j = 0;
    for(TableUnit* unit: pTD->getData()){
        map<string, string> mapMember = unit->getMapMember();
        // print header row
        if (j ==0) { 
            int i = 0;
            cout << endl << string(sumWidth + 5/*width of Id column*/, '-') << endl;
            cout << setw(5) << left << "Id"; // print Id header
            for (it = mapMember.begin(); it != mapMember.end(); it++){
                cout << setw(tableWidth[i] + 2) << left << it->first;
                i++;
            }
            cout << endl << string(sumWidth + 5/*width of Id column*/, '=') << endl;
        }
        // print all values row
        int i = 0;
        cout << setw(5) << left << j+1; // print Id value
        for (it = mapMember.begin(); it != mapMember.end(); it++){
            cout << setw(tableWidth[i] + 2) << left << it->second;
            i++;
        }
        cout << endl << string(sumWidth + 5/*width of Id column*/, '-') << endl;
        j++;
    }
    cout << endl << endl;
    // cout << ptD -> ToString();
}
void IO::dataOut(TableUnit* pTU, int id){
    vector<int> tableWidth = findUnitColumnWidth(pTU); // get vetor<int> contain column width
    int sumWidth = 0; // total width of Table
    for (int i: tableWidth) sumWidth += i + 2 /*distance between 2 column*/;
    map<string, string>::iterator it;
    map<string, string> mapMember = pTU->getMapMember();
    cout << endl << string(sumWidth + 5/*width of Id column*/, '-') << endl;
    // print header row
    cout << setw(5) << left << "Id"; // print Id header
    int i = 0;
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << setw(tableWidth[i] + 2) << left << it->first;
        i++;
    }
    cout << endl << string(sumWidth + 5/*width of Id column*/, '=') << endl;
    // print all values row
    i = 0;
    cout << setw(5) << left << id; // print Id value
    for (it = mapMember.begin(); it != mapMember.end(); it++){
        cout << setw(tableWidth[i] + 2) << left << it->second;
        i++;
    }
    cout << endl << string(sumWidth + 5/*width of Id column*/, '-') << endl;
}

void IO::dataEdit(TableData* pTD, string idName){
    dataOut(pTD); // print data in TableData
    vector<TableUnit*> vTU = pTD->getData();
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue);cin.ignore();
    for (int i = 0; i < vTU.size(); i++){
        TableUnit* pTU = vTU[i];
        if (pTU->getValue(idName) == idValue){
            dataOut(pTU, i + 1);
            dataIn(pTU);
            break;
        }
    }  
}
void IO::dataEditById(TableData* pTD){
    dataOut(pTD);
    cout << "   Enter Id: ";
    int id = 0; cin >> id; cin.ignore();
    id--;
    TableUnit* pTU = pTD->getPtr(id);
    if (pTU == nullptr){
        cout << "   Id not found!" <<endl;
        return;
    }
    dataOut(pTU, id + 1);
    dataIn(pTU);
}
void IO::dataDelete(TableData* pTD, string idName){
    dataOut(pTD);
    vector<TableUnit*> vTU = pTD->getData();
    cout << "   Enter " << idName << ": ";
    string idValue = ""; getline(cin, idValue); //cin.ignore();   
    for (int i = 0; i < vTU.size(); i++){
        TableUnit* pTU = vTU[i];
        if (pTU->getValue(idName) == idValue){
            dataOut(pTU, i + 1);
            cout << "   Delete this unit?" << endl;
            cout << "   1.Yes." << endl;
            cout << "   2.No."  << endl;
            int select = 0; cin >> select; cin.ignore();
            if (select == 1) pTD->delele(i);
            break;
        }
    }
}
void IO::dataDeleteById(TableData* pTD){
    dataOut(pTD);
    cout << "   Enter Id: ";
    int id = 0; cin >> id; cin.ignore();
    id--;
    TableUnit* unit = pTD->getPtr(id);
    if (unit == nullptr){
        cout << "   Id not found!" <<endl;
        return;
    }
    dataOut(unit, id + 1);
    cout << "   Delete this unit?" << endl;
    cout << "   1.Yes." << endl;
    cout << "   2.No."  << endl;
    int select = 0; cin >> select; cin.ignore();
    if (select == 1) pTD->delele(id);
}
int IO::saveData(TableData* pTD, string filepath){
    string datetime = Utility::getDatetimeString();
    ofstream outFile(filepath);
    if(!outFile) return 0;
    for (auto pTU: pTD->getData()){
        outFile << pTU->toStringEncode() << endl;
    }
    outFile.close();
    return 1;
}
int IO::loadData(TableData* pTD, string filepath){
    pTD->deleleAll();
    ifstream inFile(filepath);
    if(!inFile) return 0;
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        string s = buff;
        TableUnit *pTU = pTD->getTableUnit();
        pTU->fromStringDecode(s);
        pTD->push(pTU);
    }
    inFile.close();
    return 1;
}