#ifndef Project_businessobject_WorksOn_h_
#define Project_businessobject_WorksOn_h_

#include <string>
using namespace std;

class WorksOn{
    int Id;
    long ESSN;
    int PNO;
    double Hours;
public:
    WorksOn();
    WorksOn(int id, long eSSN, int pno, double hours);
    
};
#endif