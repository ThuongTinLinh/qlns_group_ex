#ifndef Project_ui_IO_h_
#define Project_ui_IO_h_

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "..\businessobject\TableUnit.h"
#include "..\businessobject\Employee.h"
#include "..\dataprocessing\TableData.h"
#include "..\libs\Utility.h"
using namespace std;

class IO{
protected:
public:
    IO();
    /** @brief Function that get data of a new TableUnit from user.
     * 
     * @details print instructions and get equivalent data of a new TableUnit from user.
     * @param pTU a pointer point to a TableUnit.
    */
    void dataIn(TableUnit* pTU);

    /** @brief Function that get data of a new TableData from user.
     * 
     * @details print instructions and get equivalent data of a new TableData from user.
     * @param pTD a pointer point to a TableData.
    */
    void dataIn(TableData* pTD);

    /** @brief Function that print data of a TableUnit.
     * 
     * @param pTU a pointer point to a TableUnit.
     * @param id index of this TableUnit*
    */
    void dataOut(TableUnit* pTU, int id);

    /** @brief Function that print data of a TableData.
     * 
     * @param pTD a pointer point to a TableData. 
    */
    void dataOut(TableData* pTD);

    /** @brief Function that find and edit data in a TableData.
     * 
     * @details find data in a TableData by its value and name, then edit it by user.
     * @param pTD a pointer point to a TableData.
     * @param idName name of the attribute to find data in TableData.
    */
    void dataEdit(TableData* pTD, string idName);

    /** @brief Function that edit data at an Id in a TableData.
     * 
     * @details find data in a TableData by its Id, then edit it by user.
     * @param pTD a pointer point to a TableData.
    */
    void dataEditById(TableData* pTD);

    /** @brief Function that find and delete data in a TableData.
     * 
     * @details find data in a TableData by its value and name, the delete it with users permission.
     * @param pTD a pointer point to a TableData.
     * @param idName name of the attribute to find data in TableData.
    */
    void dataDelete(TableData* pTD, string idName);

    /** @brief Function that delete data at an Id in a TableData.
     * 
     * @details find data in a TableData by its Id, the delete it with users permission.
     * @param pTD a pointer point to a TableData.
    */
    void dataDeleteById(TableData* pTD);

    /** @brief Function that save a TableData to a .data file.
     * 
     * @details save a TableData as a encoded string at a .data file,
     * the file name has information of the save time.
     * @param pTD a pointer point to a TableData.
     * @param filename name of the folder.
     * 
    */
    int saveData(TableData* pTD, string filename);

    /** @brief Function that load a TableData from a .data file.
     * 
     * @details load data as a encoded string at a specific .data file path,
     * decode the string then transform it to a TableData.
     * @param pTD a pointer point to a TableData.
     * @param filepath filepath to .data file.
    */
    int loadData(TableData* pTD, string filepath);
};

#endif // Project_ui_IO_h_