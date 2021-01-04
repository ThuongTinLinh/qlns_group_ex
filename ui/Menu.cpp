#include "Menu.h"

Menu::Menu(Solution *solutionData){
    SolutionData = solutionData;
};

void Menu::Home(){
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
            Mn1_CRUD();
            break;
        case 2:
            cout << "   2. Displays employees of manager." << endl;
            Mn2_ShowEmployeeOfManager();
            break;
        case 3:
            cout << "   3. Displays employees has daughter or son." << endl;
            Mn3_ShowEmployeeHasDependent();
            break;
        case 4:
            cout << "   4. Displays time of project." << endl;
            Mn4_ShowProjecTime();
            break;
        case 5:
            cout << "   5. Displays employees are free." << endl;
            Mn5_ShowFreeEmployee();
            break;
        case 6:
            cout << "   6. Displays the average salary of the department." << endl;
            Mn6_ShowDepartmentAvgSalary();
            break;
        case 7:
            cout << "   7. Displays the average salary of the sex." << endl;
            Mn7_ShowSexAvgSalary();
            break;
        case 8:
            cout << "   8. Displays managers with no dependents." << endl;
            Mn8_ManagerNoDependent();
            break;
        case 9:
            cout << "   9. Displays hard working employees in department project." << endl;
            Mn9_minTimeWorkOnAtDependent();
            break;
        case 10:
            cout << "  10. Backup and Restore data." << endl;
            Mn10_BackupAndRestore();
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
void Menu::Mn1_CRUD(){
    int Mn1_Select = 0;
    do{
        //cout << "   Add, Edit, delete or read data."<< endl;
        cout << "   0. Quit." << endl;
        cout << "   1. Add." << endl;
        cout << "   2. Edit." << endl;
        cout << "   3. Delete." << endl;
        cout << "   4. Read." << endl;

        cin >> Mn1_Select; cin.ignore();
        if (Mn1_Select < 0 || Mn1_Select > 4){
            cout << "   Wrong Selection!" << endl;
            continue;
        }        
        
        int Add_Select = 0;
        SelectTable();        
        cin >> Add_Select; cin.ignore();
        if (Add_Select == 0) break;
        if (Add_Select < 1 || Add_Select > 6){
            cout << "   Wrong Selection!" << endl;
            continue;
        }
        SolutionData->Q1_AddToTable(Add_Select);

        switch (Mn1_Select){
            case 1:{
                SolutionData->Q1_AddToTable(Add_Select);
                break;
            }
            case 2:{
                SolutionData->Q1_EditTable(Edit_Select);
                break;
            }
            case 3:{
                SolutionData->Q1_DeleteInTable(Delete_Select);
                break;
            }
            case 4:{
                SolutionData->Q1_ReadTable(Read_Select);
                break;
            }

        }
    }while(Mn1_Select != 0);
    
    
    
};
void Menu::Mn2_ShowEmployeeOfManager(){
    string mngName;
    cout << "   Please enter Manager Name (ex: 'Franklin Wong') : ";
    getline(cin, mngName);    
    vector<vector<string>> employees = SolutionData->Q2_ShowEmployeeOfManager(mngName);
    // Display data
    cout<<"*Employee list managed by " + mngName + " : " << endl;
    for(vector<string> vts : employees){
        cout <<  "    " + vts[0] + "(" + vts[1] + ")" <<endl;
    };
};
void Menu::Mn3_ShowEmployeeHasDependent(){
    vector<vector<string>> employees = SolutionData->Q3_ShowEmployeeHasDependent();
    // Display data
    cout<<"*List of employees without children:" << endl;
    for(vector<string> vts : employees){
        cout <<  "    " + vts[0] + "(" + vts[1] + ") has " + vts[2] + " is " + vts[3] <<endl;
    };
};
void Menu::Mn4_ShowProjecTime(){
    vector<vector<string>> ptimes = SolutionData->Q4_ShowProjecTime();
    // Display data
    cout<<"*Project list :" << endl;
    for(vector<string> vts : ptimes){
        cout <<  "    Project " + vts[0] +  " (PNO:" + vts[1] + ") has total time is " + vts[2] + "h" <<endl;
    };
};
void Menu::Mn5_ShowFreeEmployee(){    
    vector<vector<string>> employees = SolutionData->Q5_ShowFreeEmployee();
    // Display data
    cout<<"*Employee list is free :" << endl;
    for(vector<string> vts : employees){
            cout << "    " + vts[0] +  " (PNO:" + vts[1] + ") is free" <<endl;
    };
};
void Menu::Mn6_ShowDepartmentAvgSalary(){
    string dName;
    cout << "   Please enter department Name (ex: 'Research') : ";
    cin >> dName;
    long dAvgSalarys = SolutionData->Q6_ShowDepartmentAvgSalary(dName);
    // Display data
    cout <<"*" +dName + " has avg salary = " + to_string(dAvgSalarys) + "$" <<endl;
    
};
void Menu::Mn7_ShowSexAvgSalary(){
    string sex;
    cout << "   Please enter sex (ex: 'M') : ";
    cin >> sex;
    long sexAvgSalary = SolutionData->Q7_ShowSexAvgSalary(sex);
    // Display data
    cout << "*'" + sex + "' sex has avg salary = " + to_string(sexAvgSalary) + "$" <<endl;
};
void Menu::Mn8_ManagerNoDependent(){
    vector<vector<string>> mgrs = SolutionData->Q8_ManagerNoDependent();
    // Display data
    cout<<"*Management list has no dependents :" << endl;
    for(vector<string> vts : mgrs){
        cout << "    Manager " + vts[0] + " (" + vts[1] + ") has't dependent " <<endl;
    };
};
void Menu::Mn9_minTimeWorkOnAtDependent(){
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
    vector<vector<string>> mgrs = SolutionData->Q9_minTimeWorkOnAtDependent(dNumber, pName, minTimeWorksOn);
    // Display data
    cout<<"*List of employees with working conditions in the department :" << endl;
    for(vector<string> vts : mgrs){
        cout << "    " + vts[0] + " (SSN : " + vts[1] + ") project " + pName + " in department " + to_string(dNumber)
                    + " is workon " +  vts[2] + " >= " + to_string(minTimeWorksOn)  + "h" <<endl;
    };
};
void Menu::Mn10_BackupAndRestore(){
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
                result = SolutionData->Q10_Backup(backup_Select, folderPath);
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
                result = SolutionData->Q10_Restore(restore_Select, folderPath);
                if (result) cout << "   Restore from " << folderPath << " done!" <<endl;
            }while(restore_Select != 0);
        }
    }while(mn10_Select != 0);
    
    /*if(select == 1){
        //CompanyData->Q10_Backup();                                                    // todo
        cout << "   Done backup." << endl;
    } else if(select == 2){
        // vector<string> listVer = CompanyData->Q10_GetListVerRestore();               // todo
        // for(int i; i < listVer.size(); i++){
        //     cout << "   " + to_string(i) + ". ver " + listVer[0] << endl;
        // }
        // cout << "Please chose : " << endl;
        // cin >> select;
        // if(select >= listVer.size()) {
        //     select = 0;
        // }
        // string selectVer = listVer[select];
        // CompanyData->Q10_Restore(selectVer);                                         // todo
        cout << "   Done restore." << endl;
    } else {
        cout << "don't backup or restore " << endl;
    }*/
    
}