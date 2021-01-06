#include "Employee.h"

Employee::Employee(){}

Employee::Employee(string fName, string mInit, string lName, long ssn, string bDate, string address, string sex, int salary, long superSSN, int dno){
    _fName = fName;
    _mInit = mInit;
    _lName = lName;
    _ssn = ssn;
    _bDate = bDate;
    _address= address;
    _sex = sex;
    _salary = salary;
    _superSSN = superSSN;
    _dno = dno;
}

// ========Override========
int Employee::fromMapMember(){
    try{
    _fName = _member["FName"];
    _mInit = _member["MInit"];
    _lName = _member["LName"];
    _ssn= stol(_member["SSN"]);
    _bDate = _member["BDate"];
    _address = _member["Address"];
    _sex= _member["Sex"];
    _salary = stoi(_member["Salary"]);
    if(_member["SuperSSN"] == "null"){
        _superSSN = -1;
    } else {
        _superSSN = stol(_member["SuperSSN"]);
    }
    _dno = stoi(_member["DNO"]);
    } catch (...) { return 0;};
    return 1;
}
void Employee::toMapMember(){
    _member["FName"] = _fName;
    _member["MInit"] = _mInit;
    _member["LName"] = _lName;
    _member["SSN"] = to_string(_ssn);
    _member["BDate"] =_bDate;
    _member["Address"] = _address;
    _member["Sex"] = _sex;
    _member["Salary"] = to_string(_salary);
    if(_superSSN == -1){
        _member["SuperSSN"] = "null";
    } else {
        _member["SuperSSN"] = to_string(_superSSN);
    }
    _member["DNO"] = to_string(_dno);
}
TableUnit *Employee::clonePtr(){
    TableUnit *pU = new Employee();
    return pU;
}
