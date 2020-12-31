#ifndef Project_libs_Utility_H_
#define Project_libs_Utility_H_
#include <string>
#include <vector>

using namespace std;
class Utility{
public:
    static string SDecode(string s);
    static string SEncode(string s);
    static string ToString(vector<string>);
    static vector<string> FromString(string s);
};
#endif