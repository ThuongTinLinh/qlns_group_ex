#include <iostream>
#include "dataprocessing\Company.h"
#include "ui\Menu.h"
using namespace std;

 
int main(){
    int i;
    cout << "-- QLNS Group Linh Thuong Tin --" << endl;
    cout << "----------------Init infor---------------------"<< endl;
    Company company;
    company.InitData();    
    cout << "----------------Show all infor---------------------"<< endl;
    company.ShowAllData();        
    cout << "----------------Question---------------------"<< endl;
    Menu menu(&company);
    menu.Home();
    cout << "----------------end---------------------"<< endl;
    return 0;
}
