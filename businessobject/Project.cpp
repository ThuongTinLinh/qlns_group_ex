//#include <string>
#include "Project.h"

Project::Project(){};

Project::Project(string pName, int pNumber, string PLocation, int dNum){
    this->PName = pName;
    this->PNumber = pNumber;
    this->PLocation = PLocation;//undefined if don't have this pointer
    this->DNum = dNum;
};
Project::Project(vector<string> vt){
    FromVt(vt);
};

// ========Override========

void Project::FromMapMember(){
    PName = Member["PName"];
    PNumber = stoi(Member["PNumber"]);
    PLocation = Member["PLocation"];
    DNum = stoi(Member["DNum"]);
}
void Project::ToMapMember(){
    Member["PName"] = PName;
    Member["PNumber"] = to_string(PNumber);
    Member["PLocation"] = PLocation;
    Member["DNum"] = to_string(DNum);
}