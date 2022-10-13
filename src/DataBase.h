#ifndef _DataBase_H_
#define _DataBase_H_

#include <cstring>
#include <string>
#include <sqlite3.h>

#define DataBase_UNIT_TEST 4

typedef enum {
    Create_Table,
    INSERT_Operation,
    SELECT_Operation,
    mx_qry,
}TenumQry;

class DataBase
{
private:
    std::string DB_name;
    sqlite3 *db;
    char * Err;
    bool isClosed;
public:
    DataBase(std::string s);
    ~DataBase();
    bool Open();
    bool Close();
    bool ExecuteQry(TenumQry qry,int const& Averge,int const& Accumulation);
};


#ifdef DataBase_UNIT_TEST
bool DataBase_unitTest();
#endif


#endif //_DataBase_H_