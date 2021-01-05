#include <iostream>
#include "ui\Solution.h"
#include "ui\Menu.h"
using namespace std;

 
int main(){
    int i;
    cout << "-- QLNS Group Linh Thuong Tin --" << endl;
    cout << "----------------Init infor---------------------"<< endl;
    Solution solution;
    solution.initData();    
    cout << "----------------Show all infor---------------------"<< endl;
    solution.showAllData();        
    cout << "----------------Question---------------------"<< endl;
    Menu menu(&solution);
    menu.home();
    cout << "----------------end---------------------"<< endl;
    return 0;
}
