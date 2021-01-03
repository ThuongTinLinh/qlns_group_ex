#include <iostream>
#include "ui\Solution.h"
#include "ui\Menu.h"
using namespace std;

 
int main(){
    int i;
    cout << "-- QLNS Group Linh Thuong Tin --" << endl;
    cout << "----------------Init infor---------------------"<< endl;
    Solution solution;
    solution.InitData();    
    cout << "----------------Show all infor---------------------"<< endl;
    solution.ShowAllData();        
    cout << "----------------Question---------------------"<< endl;
    Menu menu(&solution);
    menu.Home();
    cout << "----------------end---------------------"<< endl;
    return 0;
}
