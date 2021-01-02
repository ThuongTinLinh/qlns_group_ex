#include "Employee.h"

Employee::Employee(){};

Employee::Employee(string fName, string mInit, string lName, long ssn, string bDate, string address, string sex, int salary, long superSSN, int dno){
    FName = fName;
    MInit = mInit;
    LName = lName;
    SSN = ssn;
    BDate = bDate;
    Address = address;
    Sex = sex;
    Salary = salary;
    SuperSSN = superSSN;
    DNO = dno;
};

Employee::Employee(vector<string> vt){
    FromVt(vt);
};

// ========Override========
void Employee::FromMapMember(){
    FName = Member["FName"];
    MInit = Member["MInit"];
    LName = Member["LName"];
    SSN = stol(Member["SSN"]);
    BDate = Member["BDate"];
    Address = Member["Address"];
    Sex = Member["Sex"];
    Salary = stoi(Member["Salary"]);
    SuperSSN = stol(Member["SuperSSN"]);
    DNO = stoi(Member["DNO"]);
}
void Employee::ToMapMember(){
    Member["FName"] = FName;
    Member["MInit"] = MInit;
    Member["LName"] = LName;
    Member["SSN"] = to_string(SSN);
    Member["BDate"] = BDate;
    Member["Address"] = Address;
    Member["Sex"] = Sex;
    Member["Salary"] = to_string(Salary);
    Member["SuperSSN"] = to_string(SuperSSN);
    Member["DNO"] = to_string(DNO);
}
