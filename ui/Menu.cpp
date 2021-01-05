#include "Menu.h"

Menu::Menu(Solution *solutionData){
    _solutionData = solutionData;
}

void Menu::home(){
    int select;
    system("pause");
    do{
        system("CLS");
        select = 0;
        cout << "Home" << endl;
        cout << "   0. Quit." << endl;
        cout << "   1. Add, edit, delete or read data." << endl;
        cout << "   2. Displays employees of manager." << endl;
        cout << "   3. Displays employees has daughter or son." << endl;
        cout << "   4. Displays time of project." << endl;
        cout << "   5. Displays employees are free." << endl;
        cout << "   6. Displays the average salary of the department." << endl;
        cout << "   7. Displays the average salary of the sex." << endl;
        cout << "   8. Displays managers with no dependents." << endl;
        cout << "   9. Displays hard working employees in department project." << endl;
        cout << "  10. Backup and Restore data." << endl;
        cout << "Please enter number of task: ";
        cin >> select; cin.ignore(); 
        cout << endl;
        switch (select)
        {
        case 0:
            cout << "   Quit." << endl;
            break;
        case 1:
            //cout << "   Add, edit, delete or read data." << endl;
            mn1_CRUD();
            break;
        case 2:
            cout << "   Displays employees of manager." << endl;
            mn2_ShowEmployeeOfManager();
            break;
        case 3:
            cout << "   Displays employees has daughter or son." << endl;
            mn3_ShowEmployeeHasDependent();
            break;
        case 4:
            cout << "   Displays time of project." << endl;
            mn4_ShowProjecTime();
            break;
        case 5:
            cout << "   Displays employees are free." << endl;
            mn5_ShowFreeEmployee();
            break;
        case 6:
            cout << "   Displays the average salary of the department." << endl;
            mn6_ShowDepartmentAvgSalary();
            break;
        case 7:
            cout << "   Displays the average salary of the sex." << endl;
            mn7_ShowSexAvgSalary();
            break;
        case 8:
            cout << "   Displays managers with no dependents." << endl;
            mn8_ManagerNoDependent();
            break;
        case 9:
            cout << "   Displays hard working employees in department project." << endl;
            mn9_minTimeWorkOnAtDependent();
            break;
        case 10:
            //cout << "   Backup and Restore data." << endl;
            mn10_BackupAndRestore();
            break;        
        default:
            cout << "   Wrong Selection!" << endl;
            select = 0;
            break;
        }
        system("pause");
    }while(select != 0);
}
void SelectTable(){
    cout << "   Select Table :" << endl;
    cout << "   0. Quit." << endl;
    cout << "   1. EMPLOYEE." << endl;
    cout << "   2. DEPARTMENT." << endl;
    cout << "   3. DEPENDENT." << endl;
    cout << "   4. DEPT LOCATION." << endl;
    cout << "   5. PROJECT." << endl;
    cout << "   6. WORKS ON." << endl;
    cout << "Please chose : " << endl;
}
void Menu::mn1_CRUD(){
    
    do{
        system("CLS");
        int tableSelect = 0;
        SelectTable();   
        cin >> tableSelect; cin.ignore(); 
        if (tableSelect == 0) break;
        if (tableSelect < 1 || tableSelect > 6){
            cout << "   Wrong Selection!" << endl;
            break;
        }

        int mn1_Select = 0;
        cout << "   Add, edit, delete or read data." << endl;
        cout << "   0. Quit." << endl;
        cout << "   1. Add." << endl;
        cout << "   2. Edit." << endl;
        cout << "   3. Delete." << endl;
        cout << "   4. Read." << endl;
        cout << "Please chose : " << endl;
        
        cin >> mn1_Select; cin.ignore(); 
        if (mn1_Select == 0) break;
        if (mn1_Select < 1 || mn1_Select > 4){
            cout << "   Wrong Selection!" << endl;
            break;
        }        
        

        switch (mn1_Select){
            case 1:{
                _solutionData->q1_AddToTable(tableSelect);
                break;
            }
            case 2:{
                _solutionData->q1_EditTable(tableSelect);
                break;
            }
            case 3:{
                _solutionData->q1_DeleteInTable(tableSelect);
                break;
            }
            case 4:{
                _solutionData->q1_ReadTable(tableSelect);
                break;
            }
        }
        system("pause");
    }while(true);
    
    
    
}
void Menu::mn2_ShowEmployeeOfManager(){
    string mngName;
    cout << "   Please enter Manager Name (ex: 'Franklin Wong') : ";
    getline(cin, mngName); //cin.ignore();   
    vector<vector<string>> employees = _solutionData->q2_ShowEmployeeOfManager(mngName);
    if(employees.size() == 0){
        cout<<"* not found employee has manager by " << mngName << endl;
        return;
    }
    // Display data
    cout<<"*Employee list managed by " + mngName + " : " << endl;
    for(vector<string> vts : employees){
        cout <<  "    " + vts[0] + "(" + vts[1] + ")" <<endl;
    }
}
void Menu::mn3_ShowEmployeeHasDependent(){
    vector<vector<string>> employees = _solutionData->q3_ShowEmployeeHasDependent();   
    if(employees.size() == 0){
        cout<<"* not found employee has son or daughter" << endl;
        return;
    }
    // Display data
    cout<<"*List of employees without children:" << endl;
    for(vector<string> vts : employees){
        cout <<  "    " + vts[0] + "(" + vts[1] + ") has " + vts[2] + " is " + vts[3] <<endl;
    }
}
void Menu::mn4_ShowProjecTime(){
    string pName;
    cout << "   Please enter Project Name (ex: 'ProductX') : ";
    getline(cin, pName); //cin.ignore();   
    vector<vector<string>> ptimes = _solutionData->q4_ShowProjecTime(pName);   
    if(ptimes.size() == 0){
        cout<<"* not found Project" << pName << endl;
        return;
    }
    // Display data
    for(vector<string> vts : ptimes){
        cout <<  "*Project " + vts[0] +  " (PNO:" + vts[1] + ") has total time is " + vts[2] + "h" <<endl;
    }
}
void Menu::mn5_ShowFreeEmployee(){    
    vector<vector<string>> employees = _solutionData->q5_ShowFreeEmployee();   
    if(employees.size() == 0){
        cout<<"* not found free employee"  << endl;
        return;
    }
    // Display data
    cout<<"*Employee list is free :" << endl;
    for(vector<string> vts : employees){
            cout << "    " + vts[0] +  " (PNO:" + vts[1] + ") is free" <<endl;
    }
}
void Menu::mn6_ShowDepartmentAvgSalary(){
    string dName;
    cout << "   Please enter department Name (ex: 'Research') : ";
    cin >> dName; cin.ignore();   
    long dAvgSalarys = _solutionData->q6_ShowDepartmentAvgSalary(dName);    
    if(dAvgSalarys == -1){
        cout<<"* not found employee int department " << dName << endl;
        return;
    }
    // Display data
    cout <<"*" +dName + " has avg salary = " + to_string(dAvgSalarys) + "$" <<endl;
    
}
void Menu::mn7_ShowSexAvgSalary(){
    string sex;
    cout << "   Please enter sex (ex: 'M') : ";
    cin >> sex; cin.ignore();   
    long sexAvgSalary = _solutionData->q7_ShowSexAvgSalary(sex);
    
    if(sexAvgSalary == -1){
        cout<<"* not found employee has sex " << sex << endl;
        return;
    }
    // Display data
    cout << "*'" + sex + "' sex has avg salary = " + to_string(sexAvgSalary) + "$" <<endl;
}
void Menu::mn8_ManagerNoDependent(){
    vector<vector<string>> mgrs = _solutionData->q8_ManagerNoDependent();
    if(mgrs.size() == 0){
        cout<<"* not found Management has no dependents" << endl;
        return;
    }
    // Display data
    cout<<"*Management list has no dependents :" << endl;
    for(vector<string> vts : mgrs){
        cout << "    Manager " + vts[0] + " (" + vts[1] + ") has't dependent " <<endl;
    }
}
void Menu::mn9_minTimeWorkOnAtDependent(){
    int dNumber;
    string pName;
    double minTimeWorksOn;
    cout << "Enter department number, project name, min time works on" << endl;;
    cout << "   Please enter department number (ex: '5') : ";
    cin >> dNumber; cin.ignore();   
    cout << "   Please enter project name (ex: 'ProductX') : ";
    cin >> pName; cin.ignore();   
    cout << "   Please enter minimum workon (ex: '10') : ";
    cin >> minTimeWorksOn; cin.ignore();   
    vector<vector<string>> mgrs = _solutionData->q9_minTimeWorkOnAtDependent(dNumber, pName, minTimeWorksOn);
    if(mgrs.size() == 0){
        cout<<"* not found data" << endl;
        return;
    }
    // Display data
    cout<<"*List of employees with working conditions in the department :" << endl;
    for(vector<string> vts : mgrs){
        cout << "    " + vts[0] + " (SSN : " + vts[1] + ") project " + pName + " in department " + to_string(dNumber)
                    + " is workon " +  vts[2] + " >= " + to_string(minTimeWorksOn)  + "h" <<endl;
    }
}
void Menu::mn10_BackupAndRestore(){
    do{
        system("CLS");
        cout << "Backup and restore" << endl;
        SelectTable();
        int tableSelect = 0;
        cin >> tableSelect; cin.ignore(); 
        if (tableSelect == 0) break;
        if (tableSelect < 1 || tableSelect > 6){
            cout << "   Wrong Selection!" << endl;
            continue;
        }
        
        int mn10_Select = 0;
        cout << "   Select Backup and restore" << endl;
        cout << "   0. Quit." << endl;
        cout << "   1. Backup." << endl;
        cout << "   2. Restore." << endl;
        cout << "Please chose : " ;
        cin >> mn10_Select; cin.ignore(); 
        if (mn10_Select < 0 || mn10_Select > 2){
            cout << "   Wrong Selection!" << endl;
            continue;
        }


        if (mn10_Select == 1){
            cout << "   Back up ... " << endl;
            int result = _solutionData->q10_Backup(tableSelect);
            if (result) cout << "   Backup done! " <<endl;
        }
        if (mn10_Select == 2){
            cout << "   Restore ... " << endl;
            int result = _solutionData->q10_Restore(tableSelect);
            if (result) {cout << "   Restore  done!" <<endl;}
            else {cout << "   data Backup notfound!" <<endl;}
        }
        system("pause");
    }while(true);
    
}