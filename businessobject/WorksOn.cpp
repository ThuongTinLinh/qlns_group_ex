#include "WorksOn.h"
#include <string>

WorksOn::WorksOn(){}
WorksOn::WorksOn(int id, long eSSN, int pno, double hours)
{
    Id = id;
    ESSN = eSSN;
    PNO = pno;
    Hours = hours;
}