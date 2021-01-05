#ifndef Project_dataprocessing_TableData_h_
#define Project_dataprocessing_TableData_h_

#include "../businessobject/TableUnit.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class TableData{
    vector<TableUnit*> Data;
    int Size;
    TableUnit* tableUnit;
public:
    TableData(TableUnit*);

    /** @brief Function read file, push data in vector
     *  
     *@details Function read file, push data in vector
     *@param filePath string(name file)
     *@param ptU pointer to point TableUnit)
    */
    TableData(string filePath, TableUnit* ptU);

     /** @brief Function get size vector.
     *  
     *@details Function get size vector data 
     *@return return size of vector
    */
    int GetSize();

    /** @brief Function resize vector.
     *  
     * @details Function resize vector data 
     * @param n size of vector
    */
    void Resize(int n);

    /** @brief Function add reference object 
     *  
     * @details Function add an object in list string
     * @return return string data.
    */
    string ToString();

    
    /** @brief Function 
     *  
     * @details Function 
     * @return return string data.
    */
    TableUnit* GetTableUnit();

    /** @brief Function add reference object to list of object
     *  
     *@details Function add reference object to list of object
     *@param ptU pointer point to TableUnit
     *@return return size of vector.
    */
    int Push(TableUnit *ptU);

  /** @brief Function change value an object
     *  
     *  @details Function change value an object
     *  @param  value index,
     * @param ptU pointer point to TableUnit.  
     * @return return size of vector.
     * return -1 if not true 
    */
    int Change(int index, TableUnit *ptU);

    /** @brief Function change value an object
     *  
     * @details Function change value an object
     * @param  value index 
     * @return return index
     * return -1 if not true 
    */
    int Delele(int index);
    
    /** @brief Function find return value from two input :key and value 
     *  
     * @details Function find
     * @param  key string
     * @param value string
     * @return return unit
     * return nullptr if not true.
    */
    TableUnit* Find(string key, string value);

      /** @brief Function find list data true with input
     *  
     * @details  Function find list data true with input(key and string)
     * @param  index int
     * @param  value string 
     * @return return vector vts
    */
    vector<TableUnit*> FindList(string key, string value);

     /** @brief Function check input have value in Data
     *  
     * @details Function check input have value in Data
     * @param  index int
     * @return return ptr
    */
    TableUnit* GetPtr(int index);

    /** @brief Function get data from vector TableData
     *  
     * @details Function get data from vector TableData
     * @return return data
    */
    vector<TableUnit*> GetData();
};

#endif // Project_dataprocessing_TableData_h_