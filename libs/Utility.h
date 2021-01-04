#ifndef Project_libs_Utility_H_
#define Project_libs_Utility_H_
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;
class Utility{
public:
    /** @brief Fuction that encode a string.
     * 
     * @details Function that replace all " " in a string to "$".
     * @param s the string to be encoded.
     * @return a encoded string.
    */
    static string encodeString(string s);

    /** @brief Function that decode a string.
     * 
     * @details Function that replace all "$" in a string to " ".
     * @param s the string to be decoded.
     * @return a decoded string.
    */
    static string decodeString(string s);
    
    /** @brief Function that create a string from a vector<string>.
     * 
     * @details Create a string by concatenate all elements in vector<string> in sequence,
     * each element is seperated by " ".
     * @param vs the vector<string>.
     * @return a string contains all member of vector<string>.
    */
    static string toString(vector<string> vs);

    /** @brief Function that create a vector<string> from a string.
     * 
     * @details Create a vector<string> with elements are parts of string that seperated by " ".
     * @param s the source string of vector<string>.
     * @return a vector<string> created from a string.
    */
    static vector<string> fromString(string s);

    /** @brief Fuction that get current Datetime at the format of a string.
     * 
     * @return a string reperesents for current Datetime.
    */
    static string getDatetimeString();
};
#endif