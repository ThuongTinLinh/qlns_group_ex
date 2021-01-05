//#include <string>
#include "Project.h"

Project::Project(){};

Project::Project(string pName, int pNumber, string PLocation, int dNum){
    this->_pName = pName;
    this->_pNumber= pNumber;
    this->_pLocation = PLocation;//undefined if don't have this pointer
    this->_dNum = dNum;
};
// Project::Project(vector<string> vt){
//     fromVt(vt);
// };

// ========Override========

void Project::fromMapMember(){
    _pName = _member["PName"];
    _pNumber = stoi(_member["PNumber"]);
    _pLocation = _member["PLocation"];
    _dNum= stoi(_member["DNum"]);
}
void Project::toMapMember(){
    _member["PName"] = _pName;
    _member["PNumber"] = to_string(_pNumber);
    _member["PLocation"] = _pLocation;
    _member["DNum"] = to_string(_dNum);
}
TableUnit *Project::clonePtr(){
    TableUnit *pU = new Project();
    return pU;
}