#include "Solution.h"

/**
 * contructor
*/
Solution::Solution(){
    _employeeData = new TableData(new Employee());
    _departmentData = new TableData(new Department());
    _dependentData = new TableData(new Dependent());
    _deptLocationData = new TableData(new DeptLocation());
    _projectData = new TableData(new Project());
    _worksOnData = new TableData(new WorksOn());

    _tableData.push_back(_employeeData);
    _tableData.push_back(_departmentData);
    _tableData.push_back(_dependentData);
    _tableData.push_back(_deptLocationData);
    _tableData.push_back(_projectData);
    _tableData.push_back(_worksOnData);
}

/**
 * local function for initial data
*/
void enterEmployee(TableData *);
void enterDepartment(TableData *);
void enterDependent(TableData *);
void enterDeptLocation(TableData *);
void enterProject(TableData *);
void enterWorksOn(TableData *);

void enterEmployee(TableData *data){
    Employee* tU1 = new Employee("John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", "M", 30000, 333445555, 5);
    Employee* tU2 = new Employee("Franklin", "T", "Wong", 333445555, "1955-12-08", "638 Voss, Houston, TX", "M", 40000, 888665555, 5);
    Employee* tU3 = new Employee("Alicia", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring, TX", "F", 25000, 987654321, 4);
    Employee* tU4 = new Employee("Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry, Bellaire, TX", "F", 43000, 888665555, 4);
    Employee* tU5 = new Employee("Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Humble, TX", "M", 38000, 333445555, 5);
    Employee* tU6 = new Employee("Joyce", "A", "English", 453453453, "1972-07-31", "5631 Ric, Houston, TX", "F", 25000, 333445555, 5);
    Employee* tU7 = new Employee("Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas, Houston, TX", "M", 25000, 987654321, 4);
    Employee* tU8 = new Employee("James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", "M", 55000, -1, 1);
    data->push(tU1);
    data->push(tU2);
    data->push(tU3);
    data->push(tU4);
    data->push(tU5);
    data->push(tU6);
    data->push(tU7);
    data->push(tU8);
}

void enterDepartment(TableData *data){
    Department* tU1 = new Department("Research", 5, 333445555, "1988-05-22");
    Department* tU2 = new Department("Admrstration", 4, 987654321, "1995-01-01");
    Department* tU3 = new Department("Headquarters", 1, 888665555, "1981-06-19");
    data->push(tU1);
    data->push(tU2);
    data->push(tU3);
}

void enterDependent(TableData *data){
    Dependent* tU1 = new Dependent(333445555, "Alice", "F", "1986-04-05", "DAUGHTER");
    Dependent* tU2 = new Dependent(333445555, "Theodore", "M", "1983-10-25", "SON");
    Dependent* tU3 = new Dependent(333445555, "Joy", "F", "1958-05-03", "SPOUSE");
    Dependent* tU4 = new Dependent(987654321, "Abner", "M", "1942-02-28", "SPOUSE");
    Dependent* tU5 = new Dependent(123456789, "Michael", "M", "1988-01-04", "SON");
    Dependent* tU6 = new Dependent(123456789, "Alice", "F", "1988-12-30", "DAUGHTER");
    Dependent* tU7 = new Dependent(123456789, "Elizabeth", "F", "1967-05-05", "SPOUSE");
    data->push(tU1);
    data->push(tU2);
    data->push(tU3);
    data->push(tU4);
    data->push(tU5);
    data->push(tU6);
    data->push(tU7);
}

void enterProject(TableData *data){
    Project* tU1 = new Project("ProductX", 1, "Bellaire", 5);
    Project* tU2 = new Project("ProductY", 2, "Sugarland", 5);
    Project* tU3 = new Project("ProductZ", 3, "Houston", 5);
    Project* tU4 = new Project("Computerization", 10, "Stafford", 4);
    Project* tU5 = new Project("Reorganization", 20, "Houston", 1);
    Project* tU6 = new Project("Newbenefits", 30, "Stafford", 4);
    data->push(tU1);
    data->push(tU2);
    data->push(tU3);
    data->push(tU4);
    data->push(tU5);
    data->push(tU6);
}

void enterDeptLocation(TableData *data){
    DeptLocation* tU1 = new DeptLocation(1, "Houston");
    DeptLocation* tU2 = new DeptLocation(4, "Stafford");
    DeptLocation* tU3 = new DeptLocation(5, "Bellaire");
    DeptLocation* tU4 = new DeptLocation(5, "Sugarland");
    DeptLocation* tU5 = new DeptLocation(5, "Houston");
    data->push(tU1);
    data->push(tU2);
    data->push(tU3);
    data->push(tU4);
    data->push(tU5);
}

void enterWorksOn(TableData *data){
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
    data->push(tU1);
    data->push(tU2);
    data->push(tU3);
    data->push(tU4);
    data->push(tU5);
    data->push(tU6);
    data->push(tU7);
    data->push(tU8);
    data->push(tU9);
    data->push(tU10);
    data->push(tU11);
    data->push(tU12);
    data->push(tU13);
    data->push(tU14);
    data->push(tU15);
    data->push(tU16);
}

void Solution::initData(){
    enterEmployee(_employeeData);
    enterDepartment(_departmentData);
    enterDependent(_dependentData);
    enterDeptLocation(_deptLocationData);
    enterProject(_projectData);
    enterWorksOn(_worksOnData);
}

/**
 * display data
*/
void Solution::showAllData(){
    IO myIO;
    myIO.dataOut(_employeeData);
    myIO.dataOut(_departmentData);
    myIO.dataOut(_dependentData);
    myIO.dataOut(_deptLocationData);
    myIO.dataOut(_projectData);
    myIO.dataOut(_worksOnData);
}

/**
 * For question
*/
void Solution::q1_AddToTable(int table){
    IO myIO;
    myIO.dataIn(_tableData[table-1]);
    myIO.dataOut(_tableData[table-1]);
}

void Solution::q1_EditTable(int table){
    IO myIO;
    myIO.dataEditById(_tableData[table-1]);  
    myIO.dataOut(_tableData[table-1]);      
}

void Solution::q1_DeleteInTable(int table){
    IO myIO;
    myIO.dataDeleteById(_tableData[table-1]);
    myIO.dataOut(_tableData[table-1]);
}

void Solution::q1_ReadTable(int table){
    IO myIO;
    myIO.dataOut(_tableData[table-1]);
}

vector<vector<string>> Solution::q2_ShowEmployeeOfManager(string mngNameInput){
    vector<vector<string>> eOut;
    vector<TableUnit*> employees = _employeeData->getData();
    
    // auto func = [mngNameInput](TableUnit *tU){return tU->getValue("FName") +  " " + tU->getValue("LName") == mngNameInput;};
    // vector<TableUnit*> employees1 = _employeeData->findListL(
    //     [mngNameInput](TableUnit *tU){return tU->getValue("FName") +  " " + tU->getValue("LName") == mngNameInput;}
    // );

    for(TableUnit *tU1 : employees){
        if(tU1->getValue("FName") +  " " + tU1->getValue("LName") == mngNameInput ){            // check name of manager
            string mngSSN = tU1->getValue("SSN");
            for(TableUnit *tU2 : employees){
                if(tU2->getValue("SuperSSN") == mngSSN ){                                       // check emplyees of manager
                    string eName = tU2->getValue("FName") + " " + tU2->getValue("LName");
                    string eSSN = tU2->getValue("SSN");
                    vector<string> e = {eName, eSSN};                                           // information of employee
                    eOut.push_back(e);
                }
            }
        }
    }
    return eOut;
}

vector<vector<string>> Solution::q3_ShowEmployeeHasDependent(){
    vector<TableUnit*> dependents = _dependentData->getData();
    vector<vector<string>> eOut;
    for(TableUnit *tU1 : dependents){
        string relationship = tU1->getValue("Relationship");
        if(relationship == "DAUGHTER" || relationship == "SON" ){                               // check relationship of employee
            string rName = tU1->getValue("DependentName");
            string eSSN = tU1->getValue("ESSN");
            TableUnit* employee = _employeeData->find("SSN", eSSN);
            if(employee != nullptr ){                                                           // check dependent
                string eName = employee->getValue("FName") + " " + employee->getValue("LName");
                string eSSN = employee->getValue("SSN");
                vector<string> e = {eName, eSSN, rName, relationship};
                eOut.push_back(e);
            }
        }
    }
    return eOut;
}

vector<vector<string>> Solution::q4_ShowProjecTime(int pNumberInput){
    string spNumber = to_string(pNumberInput);
    vector<TableUnit*> projects = _projectData->getData();
    vector<TableUnit*> worksOns = _worksOnData->getData();
    vector<vector<string>> eOut;
    TableUnit *tU1 = _projectData->find("PNumber", spNumber);
    if(tU1 != nullptr){
        string pName = tU1->getValue("PName");
        double workTime = 0;
        for(TableUnit *tU2 : worksOns){
            if(tU2->getValue("PNO") == spNumber ){                                       // check project number
                workTime += stod(tU2->getValue("Hours"));
            }
        }
        vector<string> e = {pName, to_string(workTime)};
        eOut.push_back(e);
    }
    return eOut;
}

vector<vector<string>> Solution::q5_ShowFreeEmployee(){
    vector<TableUnit*> employees = _employeeData->getData();
    vector<TableUnit*> worksOns = _worksOnData->getData();
    vector<vector<string>> eOut;
    for(TableUnit *tU1 : employees){
        string eNo = tU1->getValue("SSN");
        string eName = tU1->getValue("FName") + " " + tU1->getValue("MInit") + " " + tU1->getValue("LName");
        bool work = false;
        for(TableUnit *tU2 : worksOns){
            if(tU2->getValue("ESSN") == eNo && stod(tU2->getValue("Hours")) > 0){   // check working time of employees
                work = true;
                break;
            }
        }
        if(!work){
            vector<string> e = {eName, eNo};
            eOut.push_back(e);
        }
    }
    return eOut;
}

long Solution::q6_ShowDepartmentAvgSalary(string dNameInput){
    vector<TableUnit*> employees = _employeeData->getData();
    vector<TableUnit*> departments = _departmentData->getData();
    long lOut = 0;
    int iEmployee = 0;
    for(TableUnit *tU1 : departments){
        string dNo = tU1->getValue("DNumber");
        if(tU1->getValue("DName") == dNameInput){                                   // check name of dapartment
            long sumSalary = 0;
            iEmployee = 0;
            for(TableUnit *tU2 : employees){
                if(tU2->getValue("DNO") == dNo){                                    // check dapartment number of employees
                    sumSalary += stoi(tU2->getValue("Salary"));
                    iEmployee++;
                }
            }
            lOut = long(sumSalary / iEmployee);
            break;
        }        
    }
    if(iEmployee == 0){
        return -1;
    }
    return lOut;
}

long Solution::q7_ShowSexAvgSalary(string sexInput){
    vector<TableUnit*> employees = _employeeData->getData();
    long sumSalary = 0;
    int iEmployee = 0;
    for(TableUnit *tU1 : employees){
        if(tU1->getValue("Sex") == sexInput){                                       // check sex of employees
            sumSalary += stoi(tU1->getValue("Salary"));
            iEmployee++;
        }        
    }
    if(iEmployee == 0){
        return -1;
    }
    return long(sumSalary / iEmployee);
}

vector<vector<string>> Solution::q8_ManagerNoDependent(){
    vector<TableUnit*> departments = _departmentData->getData();
    vector<vector<string>> eOut;
    for(TableUnit *tU1 : departments){
        string mgrSSN = tU1->getValue("MgrSSN");
        if(_dependentData->find("ESSN", mgrSSN) == nullptr){                        // check ssn of department
            TableUnit *eMgr = _employeeData->find("SSN", mgrSSN);
            string mName = eMgr->getValue("LName");
            vector<string> e = {mName, mgrSSN};
            eOut.push_back(e);
            break;
        }        
    }
    return eOut;
}

vector<vector<string>> Solution::q9_minTimeWorkOnAtDependent(int dNumberInput, string pNameInput, double minTimeWorksOn){
    vector<TableUnit*> employees = _employeeData->getData();
    vector<TableUnit*> worksOns = _worksOnData->getData();
    vector<vector<string>> eOut;
    TableUnit *project = _projectData->find("PName", pNameInput);
    if(project != nullptr){
        string pNo = project->getValue("PNumber");
        for(TableUnit *tU1 : employees){
            if(tU1->getValue("DNO") == to_string(dNumberInput)){                            // check department number of employees
                string eSSN = tU1->getValue("SSN");
                string fullName = tU1->getValue("FName") + " " + tU1->getValue("LName");
                double sumTime = 0;
                for(TableUnit *tU2 : worksOns){
                    if(tU2->getValue("PNO") == pNo && tU2->getValue("ESSN") == eSSN){       // check project number and SSN of Workons
                        sumTime += stod(tU2->getValue("Hours"));
                    }
                }
                if(sumTime >= minTimeWorksOn ){                                             // check min time of employees
                    vector<string> e = {fullName, eSSN, to_string(sumTime)};
                    eOut.push_back(e);
                }
            }
        }
    }
    return eOut;
}

int Solution::q10_Backup(int table){
    IO myIO;
    int result = 0;
    result = myIO.saveData(_tableData[table-1], "data\\" + to_string(table) + ".data");
    return result;
}

int Solution::q10_Restore(int table){
    IO myIO;
    int result = 0;
    result = myIO.loadData(_tableData[table-1], "data\\" + to_string(table) + ".data");
    return result;
}