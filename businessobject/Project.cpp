//#include <string>
#include "Project.h"

Project::Project(){};

Project::Project(string pName, int pNumber, string PLocation, int dNum){
    this->_pName = pName;
    this->_pNumber= pNumber;
    this->_pLocation = PLocation;//undefined if don't have this pointer
    this->_dNum = dNum;
};
Project::Project(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void Project::fromMapMember(){
    _pName = Member["PName"];
    _pNumber = stoi(Member["PNumber"]);
    _pLocation = Member["PLocation"];
    _dNum= stoi(Member["DNum"]);
}
void Project::toMapMember(){
    Member["PName"] = _pName;
    Member["PNumber"] = to_string(_pNumber);
    Member["PLocation"] = _pLocation;
    Member["DNum"] = to_string(_dNum);
}
TableUnit *Project::ClonePtr(){
    TableUnit *pU = new Project();
    return pU;
}