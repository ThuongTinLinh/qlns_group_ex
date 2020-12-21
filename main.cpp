#include <iostream>
#include "businessobject\Employee.h"
#include "businessobject\Department.h"
#include "businessobject\DeptLocation.h"
#include "businessobject\Project.h"
#include "businessobject\WorksOn.h"
#include "businessobject\Dependent.h"
//haha
//hihi
using namespace std;

int main(){
    cout << "-- QLNS Group Linh Thuong Tin --" << endl;
    Employee nbc(1, "Chau", "Bao", "Ngo", 111222333, "1975-04-30", "Chicago", 'M', 10000, -1, 5);
    Department RaD(1, "R&D Department", 5, 333444555, "20-12-2020");
    DeptLocation Dept1(1, 5, "Chicago");
    Project Prj1(1, "Porche", 23, "Chicago", 5);
    WorksOn WO1(1, 333444555, 23, 45.6);
    Dependent Dpd1(1, 333444555, "Laura", 'F', "20-11-2005", "Daughter");
    return 0;
}