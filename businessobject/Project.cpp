#include <string>
#include "Project.h"

Project::Project(){};

Project::Project(int id, string pName, int pNumber, string PLocation, int dNum){
    Id = id;
    PName = pName;
    PNumber = pNumber;
    PLocation = PLocation;
    DNum = dNum;
};