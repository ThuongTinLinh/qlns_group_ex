#ifndef _EMPLOYEES_H_
#define _EMPLOYEES_H_

#include <string>
using namespace std;
class Employee{
    int Id;// id is increasing number
    string FName, MInit, LName;
    long SSN;
    string BDate, Address;
    char Sex;
    int Salary;
    long SuperSNN;
    int DNO;
public:
    Employee();
    Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno)S
};

#endif