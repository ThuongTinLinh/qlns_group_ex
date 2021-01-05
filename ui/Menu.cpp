#include "Menu.h"

Menu::Menu(Solution *solutionData){
    _solutionData = solutionData;
};

void Menu::home(){
    int select;
    do{
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
        cin >> select;
        cin.ignore(); 
        cout << endl;
        switch (select)
        {
        case 0:
            cout << "   0. Quit." << endl;
            break;
        case 1:
            cout << "   1. Add, edit, delete or read data." << endl;
            mn1_CRUD();
            break;
        case 2:
            cout << "   2. Displays employees of manager." << endl;
            mn2_ShowEmployeeOfManager();
            break;
        case 3:
            cout << "   3. Displays employees has daughter or son." << endl;
            mn3_ShowEmployeeHasDependent();
            break;
        case 4:
            cout << "   4. Displays time of project." << endl;
            mn4_ShowProjecTime();
            break;
        case 5:
            cout << "   5. Displays employees are free." << endl;
            mn5_ShowFreeEmployee();
            break;
        case 6:
            cout << "   6. Displays the average salary of the department." << endl;
            mn6_ShowDepartmentAvgSalary();
            break;
        case 7:
            cout << "   7. Displays the average salary of the sex." << endl;
            mn7_ShowSexAvgSalary();
            break;
        case 8:
            cout << "   8. Displays managers with no dependents." << endl;
            mn8_ManagerNoDependent();
            break;
        case 9:
            cout << "   9. Displays hard working employees in department project." << endl;
            mn9_minTimeWorkOnAtDependent();
            break;
        case 10:
            cout << "  10. Backup and Restore data." << endl;
            mn10_BackupAndRestore();
            break;        
        default:
            cout << "   Quit." << endl;
            select = 0;
            break;
        }
        system("pause");
    }while(select != 0);
};
void SelectTable(){
    cout << "   0. Quit." << endl;
    cout << "   1. EMPLOYEE." << endl;
    cout << "   2. DEPARTMENT." << endl;
    cout << "   3. DEPT LOCATION." << endl;
    cout << "   4. WORKS ON." << endl;
    cout << "   5. PROJECT." << endl;
    cout << "   6. DEPENDENT." << endl;
}
void Menu::mn1_CRUD(){
    int mn1_Select = 0;
    do{
        //cout << "   Add, Edit, delete or read data."<< endl;
        cout << "   0. Quit." << endl;
        cout << "   1. Add." << endl;
        cout << "   2. Edit." << endl;
        cout << "   3. Delete." << endl;
        cout << "   4. Read." << endl;

        cin >> mn1_Select; cin.ignore();
        if (mn1_Select < 0 || mn1_Select > 4){
            cout << "   Wrong Selection!" << endl;
            continue;
        }        
        
        int select = 0;
        SelectTable();        
        cin >> select; cin.ignore();
        if (select == 0) break;
        if (select < 1 || select > 6){
            cout << "   Wrong Selection!" << endl;
            continue;
        }

        switch (mn1_Select){
            case 1:{
                _solutionData->q1_AddToTable(select);
                break;
            }
            case 2:{
                _solutionData->q1_EditTable(select);
                break;
            }
            case 3:{
                _solutionData->q1_DeleteInTable(select);
                break;
            }
            case 4:{
                _solutionData->q1_ReadTable(select);
                break;
            }
        }
    }while(mn1_Select != 0);
    
    
    
};
void Menu::mn2_ShowEmployeeOfManager(){
    string mngName;
    cout << "   Please enter Manager Name (ex: 'Franklin Wong') : ";
    getline(cin, mngName);    
    vector<vector<string>> employees = _solutionData->q2_ShowEmployeeOfManager(mngName);
    // Display data
    cout<<"*Employee list managed by " + mngName + " : " << endl;
    for(vector<string> vts : employees){
        cout <<  "    " + vts[0] + "(" + vts[1] + ")" <<endl;
    };
};
void Menu::mn3_ShowEmployeeHasDependent(){
    vector<vector<string>> employees = _solutionData->q3_ShowEmployeeHasDependent();
    // Display data
    cout<<"*List of employees without children:" << endl;
    for(vector<string> vts : employees){
        cout <<  "    " + vts[0] + "(" + vts[1] + ") has " + vts[2] + " is " + vts[3] <<endl;
    };
};
void Menu::mn4_ShowProjecTime(){
    vector<vector<string>> ptimes = _solutionData->q4_ShowProjecTime();
    // Display data
    cout<<"*Project list :" << endl;
    for(vector<string> vts : ptimes){
        cout <<  "    Project " + vts[0] +  " (PNO:" + vts[1] + ") has total time is " + vts[2] + "h" <<endl;
    };
};
void Menu::mn5_ShowFreeEmployee(){    
    vector<vector<string>> employees = _solutionData->q5_ShowFreeEmployee();
    // Display data
    cout<<"*Employee list is free :" << endl;
    for(vector<string> vts : employees){
            cout << "    " + vts[0] +  " (PNO:" + vts[1] + ") is free" <<endl;
    };
};
void Menu::mn6_ShowDepartmentAvgSalary(){
    string dName;
    cout << "   Please enter department Name (ex: 'Research') : ";
    cin >> dName;
    long dAvgSalarys = _solutionData->q6_ShowDepartmentAvgSalary(dName);
    // Display data
    cout <<"*" +dName + " has avg salary = " + to_string(dAvgSalarys) + "$" <<endl;
    
};
void Menu::mn7_ShowSexAvgSalary(){
    string sex;
    cout << "   Please enter sex (ex: 'M') : ";
    cin >> sex;
    long sexAvgSalary = _solutionData->q7_ShowSexAvgSalary(sex);
    // Display data
    cout << "*'" + sex + "' sex has avg salary = " + to_string(sexAvgSalary) + "$" <<endl;
};
void Menu::mn8_ManagerNoDependent(){
    vector<vector<string>> mgrs = _solutionData->q8_ManagerNoDependent();
    // Display data
    cout<<"*Management list has no dependents :" << endl;
    for(vector<string> vts : mgrs){
        cout << "    Manager " + vts[0] + " (" + vts[1] + ") has't dependent " <<endl;
    };
};
void Menu::mn9_minTimeWorkOnAtDependent(){
    int dNumber;
    string pName;
    double minTimeWorksOn;
    cout << "Enter department number, project name, min time works on" << endl;;
    cout << "   Please enter department number (ex: '5') : ";
    cin >> dNumber;
    cout << "   Please enter project name (ex: 'ProductX') : ";
    cin >> pName;
    cout << "   Please enter minimum workon (ex: '10') : ";
    cin >> minTimeWorksOn;
    vector<vector<string>> mgrs = _solutionData->q9_minTimeWorkOnAtDependent(dNumber, pName, minTimeWorksOn);
    // Display data
    cout<<"*List of employees with working conditions in the department :" << endl;
    for(vector<string> vts : mgrs){
        cout << "    " + vts[0] + " (SSN : " + vts[1] + ") project " + pName + " in department " + to_string(dNumber)
                    + " is workon " +  vts[2] + " >= " + to_string(minTimeWorksOn)  + "h" <<endl;
    };
};
void Menu::mn10_BackupAndRestore(){
    int mn10_Select = 0;
    do{
        cout << "Backup and restore" << endl;
        cout << "   0. Quit." << endl;
        cout << "   1. Backup." << endl;
        cout << "   2. Restore." << endl;
        cout << "Please chose : " << endl;
        cin >> mn10_Select; cin.ignore();
        if (mn10_Select < 0 || mn10_Select > 2){
            cout << "   Wrong Selection!" << endl;
            continue;
        }
        if (mn10_Select == 1){
            int backup_Select = 0;
            int result = 0;
            do{
                cout << "   Back up table : " << endl;
                SelectTable();
                cin >> backup_Select; cin.ignore();
                if (backup_Select == 0) break;
                if (backup_Select < 1 || backup_Select > 6){
                    cout << "   Wrong Selection!" << endl;
                    continue;
                }
                cout << "   Enter Folder Path: ";
                string folderPath = ""; getline(cin, folderPath);
                if (folderPath == ""){
                    cout << "   Wrong Folder Path!";
                    continue;
                }
                result = _solutionData->q10_Backup(backup_Select, folderPath);
                if (result) cout << "   Back up to " << folderPath << " done!" <<endl;
            }while(backup_Select != 0);
        }
        if (mn10_Select == 2){
            int restore_Select = 0;
            int result = 0;
            do{
                cout << "   Restore table : " << endl;
                SelectTable();
                cin >> restore_Select; cin.ignore();
                if (restore_Select == 0) break;
                if (restore_Select < 1 || restore_Select > 6){
                    cout << "   Wrong Selection!" << endl;
                    continue;
                }
                cout << "   Enter Folder Path: ";
                string folderPath = ""; getline(cin, folderPath);
                if (folderPath == ""){
                    cout << "   Wrong Folder Path!";
                    continue;
                }
                result = _solutionData->q10_Restore(restore_Select, folderPath);
                if (result) cout << "   Restore from " << folderPath << " done!" <<endl;
            }while(restore_Select != 0);
        }
    }while(mn10_Select != 0);
    
}