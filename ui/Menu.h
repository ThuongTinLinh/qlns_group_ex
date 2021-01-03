#ifndef Project_ui_Menu_h_
#define Project_ui_Menu_h_

#include "..\ui\Solution.h"
#include "..\ui\IO.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Menu{
protected:
    Solution *SolutionData;
public:
    Menu(Solution *solutionData);
    void Home();
    void Mn1_CRUD();
    void Mn2_ShowEmployeeOfManager();
    void Mn3_ShowEmployeeHasDependent();
    void Mn4_ShowProjecTime();
    void Mn5_ShowFreeEmployee();
    void Mn6_ShowDepartmentAvgSalary();
    void Mn7_ShowSexAvgSalary();
    void Mn8_ManagerNoDependent();
    void Mn9_minTimeWorkOnAtDependent();
    void Mn10_BackupAndRestore();
};

#endif // Project_ui_Menu_h_