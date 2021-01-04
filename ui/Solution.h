#ifndef Project_ui_Solution_h_
#define Project_ui_Solution_h_

#include "..\businessobject\TableUnit.h"
#include "..\businessobject\Employee.h"
#include "..\businessobject\Department.h"
#include "..\businessobject\Dependent.h"
#include "..\businessobject\DeptLocation.h"
#include "..\businessobject\Project.h"
#include "..\businessobject\WorksOn.h"
#include "..\dataprocessing\TableData.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Solution{
    vector<TableData*> tableData;

    TableData *EmployeeData;
    TableData *DepartmentData;
    TableData *DependentData;
    TableData *DeptLocationData;
    TableData *ProjectData;
    TableData *WorksOnData;
    
public:
    Solution();
    // ~Company();
    void InitData();
    void ShowAllData();
    void Q1_AddToTable(int);
    void Q1_EditTable(int);
    void Q1_DeleteInTable(int);
    void Q1_ReadTable(int);
    //void Q1_CRUD(TableData*, TableUnit*);
    vector<vector<string>> Q2_ShowEmployeeOfManager(string mngNameInput);
    vector<vector<string>> Q3_ShowEmployeeHasDependent();
    vector<vector<string>> Q4_ShowProjecTime();
    vector<vector<string>> Q5_ShowFreeEmployee();
    long Q6_ShowDepartmentAvgSalary(string dNameInput);
    long Q7_ShowSexAvgSalary(string sexInput);
    vector<vector<string>> Q8_ManagerNoDependent();
    vector<vector<string>> Q9_minTimeWorkOnAtDependent(int dNumberInput, string pNameInput, double minTimeWorksOn);
    int Q10_Backup(int i, string folderPath);
    int Q10_Restore(int i, string folderPath);
};

#endif // Project_dataprocessing_Company_h_