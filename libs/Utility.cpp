#include "Utility.h"

string Utility::SDecode(string s)
{
    for(int i = 0; i < s.size(); i ++)
        if (s[i] == '$')
            s[i] = ' ';
    return s;
}
string Utility::SEncode(string s)
{
    for(int i = 0; i < s.size(); i ++)
        if (s[i] == ' ')
            s[i] = '$';
    return s;
}
string Utility::ToString(vector<string> vs)
{
    string s = "";
    for(string si: vs) s = s + SEncode(si) + " ";
    s[s.length()] = 0;
    // s.erase(s.length(), 1);
    return s;
}
vector<string> Utility::FromString(string s)
{
    vector<string> vs;
    string stemp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ') {
            stemp += s[i];
        }
        else{
            vs.push_back(SDecode(stemp));
            stemp = "";
        }
    }
    return vs;
    
}