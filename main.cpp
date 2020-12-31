#include <iostream>
#include "businessobject\Employee.h"
#include "businessobject\Department.h"
#include "businessobject\Dependent.h"
#include "businessobject\DeptLocation.h"
#include "businessobject\Project.h"
#include "businessobject\WorksOn.h"
#include "dataprocessing\TableData.h"
using namespace std;

 
void EnterEmployee(TableData *);
void EnterDepartment(TableData *);
void EnterDependent(TableData *);
void EnterDeptLocation(TableData *);
void EnterProject(TableData *);
void EnterWorksOn(TableData *);
void Q2_ShowEmployeeWithManager(TableData *employeeData, string MngName);
void Q3_ShowEmployeeHasDependent(TableData *employeeData, TableData *dependent);
void Q4_ShowProjecTime(TableData *project, TableData *worksOn);
int main(){
    int i;
    cout << "-- QLNS Group Linh Thuong Tin --" << endl;
    cout << "----------------Init infor---------------------"<< endl;
    TableData *employeeData = new TableData();
    EnterEmployee(employeeData);
    TableData *departmentData = new TableData();
    EnterDepartment(departmentData);
    TableData *dependentData = new TableData();
    EnterDependent(dependentData);
    // TableData *deptLocationData = new TableData();
    // EnterDeptLocation(deptLocationData);
    TableData *projectData = new TableData();
    EnterProject(projectData);
    TableData *worksOnData = new TableData();
    EnterWorksOn(worksOnData);
    cout << "----------------Show all infor---------------------"<< endl;
    employeeData->DataOut();
    departmentData->DataOut();
    // dependentData->DataOut();
    // deptLocationData->DataOut();
    // projectData->DataOut();
    // worksOnData->DataOut();
    Q2_ShowEmployeeWithManager(employeeData, "Franklin Wong");
    Q3_ShowEmployeeHasDependent(employeeData, dependentData);
    Q4_ShowProjecTime(projectData, worksOnData);
    cout << "----------------end---------------------"<< endl;
    return 0;
}

void EnterEmployee(TableData *data){
    Employee* tU1 = new Employee("John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee* tU2 = new Employee("Franklin", "T", "Wong", 333445555, "1955-12-08", "638 Voss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee* tU3 = new Employee("Alicia", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring, TX", 'F', 25000, 987654321, 4);
    Employee* tU4 = new Employee("Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry, Bellaire, TX", 'F', 43000, 888665555, 4);
    Employee* tU5 = new Employee("Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Humble, TX", 'M', 38000, 333445555, 5);
    Employee* tU6 = new Employee("Joyce", "A", "English", 453453453, "1972-07-31", "5631 Ric, Houston, TX", 'F', 25000, 333445555, 5);
    Employee* tU7 = new Employee("Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas, Houston, TX", 'M', 25000, 987654321, 4);
    Employee* tU8 = new Employee("James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    data->Push(tU1);
    data->Push(tU2);
    data->Push(tU3);
    data->Push(tU4);
    data->Push(tU5);
    data->Push(tU6);
    data->Push(tU7);
    data->Push(tU8);
}

void EnterDepartment(TableData *data){
    Department* tU1 = new Department("Research", 5, 333445555, "1988-05-22");
    Department* tU2 = new Department("Admrstration", 4, 987654321, "1995-01-01");
    Department* tU3 = new Department("Headquarters", 1, 888665555, "1981-06-19");
    data->Push(tU1);
    data->Push(tU2);
    data->Push(tU3);
}

void EnterDependent(TableData *data){
    Dependent* tU1 = new Dependent(333445555, "Alice", 'F', "1986-04-05", "DAUGHTER");
    Dependent* tU2 = new Dependent(333445555, "Theodore", 'M', "1983-10-25", "SON");
    Dependent* tU3 = new Dependent(333445555, "Joy", 'F', "1958-05-03", "SPOUSE");
    Dependent* tU4 = new Dependent(987654321, "Abner", 'M', "1942-02-28", "SPOUSE");
    Dependent* tU5 = new Dependent(123456789, "Michael", 'M', "1988-01-04", "SON");
    Dependent* tU6 = new Dependent(123456789, "Alice", 'F', "1988-12-30", "DAUGHTER");
    Dependent* tU7 = new Dependent(123456789, "Elizabeth", 'F', "1967-05-05", "SPOUSE");
    data->Push(tU1);
    data->Push(tU2);
    data->Push(tU3);
    data->Push(tU4);
    data->Push(tU5);
    data->Push(tU6);
    data->Push(tU7);
}

void EnterProject(TableData *data){
    Project* tU1 = new Project("ProductX", 1, "Bellaire", 5);
    Project* tU2 = new Project("ProductY", 2, "Sugarland", 5);
    Project* tU3 = new Project("ProductZ", 3, "Houston", 5);
    Project* tU4 = new Project("Computerization", 10, "Stafford", 4);
    Project* tU5 = new Project("Reorganization", 20, "Houston", 1);
    Project* tU6 = new Project("Newbenefits", 30, "Stafford", 4);
    data->Push(tU1);
    data->Push(tU2);
    data->Push(tU3);
    data->Push(tU4);
    data->Push(tU5);
    data->Push(tU6);
}

void EnterDeptLocation(TableData *data){
    DeptLocation* tU1 = new DeptLocation(1, "Houston");
    DeptLocation* tU2 = new DeptLocation(4, "Stafford");
    DeptLocation* tU3 = new DeptLocation(5, "Bellaire");
    DeptLocation* tU4 = new DeptLocation(5, "Sugarland");
    DeptLocation* tU5 = new DeptLocation(5, "Houston");
    data->Push(tU1);
    data->Push(tU2);
    data->Push(tU3);
    data->Push(tU4);
    data->Push(tU5);
}

void EnterWorksOn(TableData *data){
    WorksOn* tU1 = new WorksOn(123456789, 1, 32.5);
    WorksOn* tU2 = new WorksOn(123456789, 2, 7.5);
    WorksOn* tU3 = new WorksOn(666884444, 3, 40.0);
    WorksOn* tU4 = new WorksOn(453453453, 1, 20.0);
    WorksOn* tU5 = new WorksOn(453453453, 2, 20.0);
    WorksOn* tU6 = new WorksOn(333445555, 2, 10.0);
    WorksOn* tU7 = new WorksOn(333445555, 3, 10.0);
    WorksOn* tU8 = new WorksOn(333445555, 10, 10.0);
    WorksOn* tU9 = new WorksOn(333445555, 20, 10.0);
    WorksOn* tU10 = new WorksOn(999887777, 30, 30.0);
    WorksOn* tU11 = new WorksOn(999887777, 10, 10.0);
    WorksOn* tU12 = new WorksOn(987987987, 10, 35.0);
    WorksOn* tU13 = new WorksOn(987987987, 30, 5.0);
    WorksOn* tU14 = new WorksOn(987654321, 30, 20.0);
    WorksOn* tU15 = new WorksOn(987654321, 20, 15.0);
    WorksOn* tU16 = new WorksOn(888665555, 20, 0);
    data->Push(tU1);
    data->Push(tU2);
    data->Push(tU3);
    data->Push(tU4);
    data->Push(tU5);
    data->Push(tU6);
    data->Push(tU7);
    data->Push(tU8);
    data->Push(tU9);
    data->Push(tU10);
    data->Push(tU11);
    data->Push(tU12);
    data->Push(tU13);
    data->Push(tU14);
    data->Push(tU15);
    data->Push(tU16);
}

void Q2_ShowEmployeeWithManager(TableData *employeeData, string MngName){
    cout<<"list nhan vien duoc quan ly boi :" << MngName << endl;
    vector<TableUnit*> data = employeeData->GetData();
    for(TableUnit *tU1 : data){
        if(tU1->GetValue("FName") +  " " + tU1->GetValue("LName") == MngName ){
            string mngSSN = tU1->GetValue("SSN");
            cout << MngName  << " (" << mngSSN << ") dang quan ly :" << endl;
            for(TableUnit *tU2 : data){
                if(tU2->GetValue("SuperSSN") == mngSSN ){
                    cout <<  "    " + tU2->GetValue("FName") +  " " + tU2->GetValue("LName") + "(" + tU2->GetValue("SSN") + ")" <<endl;
                }
            }
        }
    }
}
void Q3_ShowEmployeeHasDependent(TableData *employeeData, TableData *dependent){
    cout<<"list nhan vien co con :" << endl;
    vector<TableUnit*> dataEmployeeData = employeeData->GetData();
    vector<TableUnit*> dataDependent = dependent->GetData();
    for(TableUnit *tU1 : dataDependent){
        string relationship = tU1->GetValue("Relationship");
        if(relationship == "DAUGHTER" || relationship == "SON" ){
            string eSSN = tU1->GetValue("ESSN");
            for(TableUnit *tU2 : dataEmployeeData){
                if(tU2->GetValue("SSN") == eSSN ){
                    cout <<  "    " + tU2->GetValue("FName") +  " " + tU2->GetValue("LName") + "(" + tU2->GetValue("SSN") + ") co " + relationship <<endl;
                }
            }
        }
    }
}
void Q4_ShowProjecTime(TableData *project, TableData *worksOn){
    cout<<"list nhan vien co con :" << endl;
    vector<TableUnit*> dataProject = project->GetData();
    vector<TableUnit*> dataWorksOn = worksOn->GetData();
    for(TableUnit *tU1 : dataProject){
        string pNo = tU1->GetValue("PNumber");
        string pName = tU1->GetValue("PName");
        float workTime = 0;
        for(TableUnit *tU2 : dataWorksOn){
            if(tU2->GetValue("PNO") == pNo ){
                workTime += stof(tU2->GetValue("Hours"));
            }
        }
        cout <<  "Project " + pName +  " (PNO:" + pNo + ") co tong thoi gian la : " + to_string(workTime) <<endl;
    }
}