#include "Utility.h"

string Utility::decodeString(string s)
{
    for(int i = 0; i < s.size(); i ++)
        if (s[i] == '$')
            s[i] = ' ';
    return s;
}
string Utility::encodeString(string s)
{
    for(int i = 0; i < s.size(); i ++)
        if (s[i] == ' ')
            s[i] = '$';
    return s;
}
string Utility::toString(vector<string> vs)
{
    string s = "";
    for(string si: vs) s = s + encodeString(si) + " ";
    s.erase(s.length(), 1); // erase the " " at the end of string.
    return s;
}
vector<string> Utility::fromString(string s)
{
    vector<string> vs;
    string stemp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ') {
            stemp += s[i]; // create elements of vector<string>.
        }
        else{
            vs.push_back(decodeString(stemp));
            stemp = "";
        }
    }
    return vs;    
}
string Utility::getDatetimeString()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y_%H-%M-%S");
    auto str = oss.str();
    return str;
}