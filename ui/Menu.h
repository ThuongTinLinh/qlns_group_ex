#ifndef Project_ui_Menu_h_
#define Project_ui_Menu_h_

#include "..\dataprocessing\Company.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Menu{
protected:
    Company *CompanyData;
public:
    Menu(Company *companyData);
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