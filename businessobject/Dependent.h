#ifndef Project_businessobject_Dependent_h_
#define Project_businessobject_Dependent_h_

#include <string>
using namespace std;

class Dependent{
    int Id;
    long ESSN;
    string DependentName;
    char Sex;
    string BDate;
    string Relationship;
public:
    Dependent();
    Dependent(int id, long eSSN, string dependentName, char sex, string bDate, string relationship);
    
};
#endif