#include <iostream>
#include "businessobject\DeptLocation.h"
#include "dataprocessing\TableData.h"
using namespace std;

int main(){
    int i;
    cout << "-- QLNS Group Linh Thuong Tin --" << endl;
    DeptLocation dl1(1, "hihi11");
    dl1.DataOut();
    DeptLocation dl2(2, "hata11");
    TableData *listDL = new TableData();
    i = listDL->Push(&dl1);
    i = listDL->Push(&dl2);
    //i = listDL->DataIn(&dl1);
    //listDL->Delele(2);   
    //listDL->GetPtr(1)->DataOut();
    listDL->DataOut();
    cout << "----------------end---------------------"<< endl;
    return 0;
}