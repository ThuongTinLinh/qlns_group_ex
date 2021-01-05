#include "Employee.h"

Employee::Employee(){};

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
};

// Employee::Employee(vector<string> vt){
//     fromVt(vt);
// };

// ========Override========
void Employee::fromMapMember(){
    _fName = Member["FName"];
    _mInit = Member["MInit"];
    _lName = Member["LName"];
    _ssn= stol(Member["SSN"]);
    _bDate = Member["BDate"];
    _address = Member["Address"];
    _sex= Member["Sex"];
    _salary = stoi(Member["Salary"]);
    if(Member["SuperSSN"] == "null"){
        _superSSN = -1;
    } else {
        _superSSN = stol(Member["SuperSSN"]);
    }
    _dno = stoi(Member["DNO"]);
}
void Employee::toMapMember(){
    Member["FName"] = _fName;
    Member["MInit"] = _mInit;
    Member["LName"] = _lName;
    Member["SSN"] = to_string(_ssn);
    Member["BDate"] =_bDate;
    Member["Address"] = _address;
    Member["Sex"] = _sex;
    Member["Salary"] = to_string(_salary);
    if(_superSSN == -1){
        Member["SuperSSN"] = "null";
    } else {
        Member["SuperSSN"] = to_string(_superSSN);
    }
    Member["DNO"] = to_string(_dno);
}
TableUnit *Employee::clonePtr(){
    TableUnit *pU = new Employee();
    return pU;
}
