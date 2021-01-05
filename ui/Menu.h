#ifndef Project_ui_Menu_h_
#define Project_ui_Menu_h_

#include "..\dataprocessing\Solution.h"
#include "..\ui\IO.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Menu{
protected:
    Solution *_solutionData;
public:
    Menu(Solution *solutionData);
    void home();
    void mn1_CRUD();
    void mn2_ShowEmployeeOfManager();
    void mn3_ShowEmployeeHasDependent();
    void mn4_ShowProjecTime();
    void mn5_ShowFreeEmployee();
    void mn6_ShowDepartmentAvgSalary();
    void mn7_ShowSexAvgSalary();
    void mn8_ManagerNoDependent();
    void mn9_minTimeWorkOnAtDependent();
    void mn10_BackupAndRestore();
};

#endif // Project_ui_Menu_h_