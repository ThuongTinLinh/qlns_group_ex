#include <string>
#include "Project.h"

Project::Project(){};

Project::Project(string pName, int pNumber, string PLocation, int dNum){
    PName = pName;
    PNumber = pNumber;
    PLocation = PLocation;
    DNum = dNum;
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
TableUnit *Project::ClonePtr(){
    TableUnit *pU = new Project();
    return pU;
};