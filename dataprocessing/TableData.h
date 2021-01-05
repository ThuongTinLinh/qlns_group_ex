#ifndef Project_dataprocessing_TableData_h_
#define Project_dataprocessing_TableData_h_

#include "../businessobject/TableUnit.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class TableData{
    vector<TableUnit*> _data;
    TableUnit* _tableUnit;
public:
    TableData(TableUnit*);
    ~TableData();

    /** @brief Function read file, push data in vector
     *  
     *@details Function read file, push data in vector
     *@param filePath string(name file)
     *@param ptU pointer to point TableUnit)
    */
    TableData(string filePath, TableUnit* ptU);

    /** @brief Function resize vector.
     *  
     * @details Function resize vector data 
     * @param n size of vector
    */
    void resize(int n);

    /** @brief Function add reference object 
     *  
     * @details Function add an object in list string
     * @return return string data.
    */
    string toString();

    
    /** @brief Function 
     *  
     * @details Function 
     * @return return string data.
    */
    TableUnit* getTableUnit();

    /** @brief Function add reference object to list of object
     *  
     *@details Function add reference object to list of object
     *@param ptU pointer point to TableUnit
     *@return return size of vector.
    */
    int push(TableUnit *ptU);

  /** @brief Function change value an object
     *  
     *  @details Function change value an object
     *  @param  value index,
     * @param ptU pointer point to TableUnit.  
     * @return return size of vector.
     * return -1 if not true 
    */
    int change(int index, TableUnit *ptU);

    /** @brief Function change value an object
     *  
     * @details Function change value an object
     * @param  value index 
     * @return return index
     * return -1 if not true 
    */
    int delele(int index);
    
    /** @brief Function delete all value an object
     *  
     * @details Function change value an object
     * @param  value index 
    */
    void deleleAll();

    /** @brief Function find return value from two input :key and value 
     *  
     * @details Function find
     * @param  key string
     * @param value string
     * @return return unit
     * return nullptr if not true.
    */
    TableUnit* find(string key, string value);

      /** @brief Function find list data true with input
     *  
     * @details  Function find list data true with input(key and string)
     * @param  index int
     * @param  value string 
     * @return return vector vts
    */
    vector<TableUnit*> findList(string key, string value);

     /** @brief Function check input have value in Data
     *  
     * @details Function check input have value in Data
     * @param  index int
     * @return return ptr
    */
    TableUnit* getPtr(int index);

    /** @brief Function get data from vector TableData
     *  
     * @details Function get data from vector TableData
     * @return return data
    */
    vector<TableUnit*> getData();
};

#endif // Project_dataprocessing_TableData_h_