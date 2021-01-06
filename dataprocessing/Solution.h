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
#include "..\ui\IO.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Solution{
    vector<TableData*> _tableData;

    TableData *_employeeData;
    TableData *_departmentData;
    TableData *_dependentData;
    TableData *_deptLocationData;
    TableData *_projectData;
    TableData *_worksOnData;
    
public:
    /** Contructor */
    Solution();
    // ~Company();

    /** @brief init all data table
    */
    void initData();

    /** @brief display all data table
    */
    void showAllData();

    /** @brief Question 1 add element into select table
     * 
     * @param select No of table is select
    */
    void q1_AddToTable(int select);

    /** @brief Question 1 edit element of select table
     * 
     * @param select No of table is select
    */
    void q1_EditTable(int select);

    /** @brief Question 1 delete element of select table
     * 
     * @param select No of table is select
    */
    void q1_DeleteInTable(int select);

    /** @brief Question 1 read element of select table
     * 
     * @param select No of table is select
    */
    void q1_ReadTable(int select);

    /** @brief Function of displaying list of employees managed by input name.
     * 
     * @param mngNameInput Name of the manager
     * @return list information of employees
    */
    vector<vector<string>> q2_ShowEmployeeOfManager(string mngNameInput);

    /** @brief Function of displaying list of employees has daughter or son.
     *
     * @return list information of employees
    */
    vector<vector<string>> q3_ShowEmployeeHasDependent();
    
    /** @brief Function of displaying list of project information.
     *
     * @param pNumberInput no of the project
     * @return list information of project
    */
    vector<vector<string>> q4_ShowProjecTime(int pNumberInput);

    /** @brief Function of displaying list of employees is free.
     *
     * @return list information of employees
    */
    vector<vector<string>> q5_ShowFreeEmployee();

    /** @brief Function get average salary of the department.
     *
     * @param dNameInput name of the department
     * @return average salary
    */
    long q6_ShowDepartmentAvgSalary(string dNameInput);

    /** @brief Function get average salary of the sex.
     *
     * @param dNameInput type of sex
     * @return average salary
    */
    long q7_ShowSexAvgSalary(string sexInput);

    /** @brief Function get list manager has't dependent.
     *
     * @return list information of manager
    */
    vector<vector<string>> q8_ManagerNoDependent();

    /** @brief Function get list employees working more than time input of the department.
     *
     * @param dNumberInput No of depatment
     * @param pNameInput Name of project
     * @param minTimeWorksOn min work time 
     * @return list information of employees
    */
    vector<vector<string>> q9_minTimeWorkOnAtDependent(int dNumberInput, string pNameInput, double minTimeWorksOn);

    /** @brief Function backup select data to folder.
     *
     * @param i No select table
     * @return successed return to 1
     *         fail return to 0
    */
    int q10_Backup(int i);

    /** @brief Function restore select data to folder.
     *
     * @param i No select table
     * @return successed return to 1
     *         fail return to 0
    */
    int q10_Restore(int i);
};

#endif // Project_dataprocessing_Company_h_