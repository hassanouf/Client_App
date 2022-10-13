#include "DataBase.h"
#include <iostream>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      std::cout <<  azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
   }
   std::cout << "\n";
   return 0;
}


DataBase::DataBase(std::string s) : DB_name(s)
{
    this->db = nullptr;
    this->Err = nullptr;
    this->isClosed = false;
}

DataBase::~DataBase()
{
   if(!this->isClosed) {
      if(!this->Close()) {
        //throw std::system_error(ENOTCONN ,std::generic_category(), "Socket didn't close as expected" );
        //didn't find error code match data base close fail
      }
   }
}

bool DataBase::Open() {
    int ret = SQLITE_ERROR; 
    ret = sqlite3_open(this->DB_name.c_str(), &this->db);
    return ret == SQLITE_OK; // return true on opening data base
}

bool DataBase::Close() {
    int ret = SQLITE_ERROR; 
    ret = sqlite3_close(this->db);
    this->isClosed = true;
    return ret == SQLITE_OK; // return true on closing data base 
}
bool DataBase::ExecuteQry(TenumQry qry,int const& Averge,int const& Accumulation) {
    int ret = SQLITE_ERROR;
    std::string str_qry;
    char buff[60];

    std::memset(buff, 0 , 60);

    switch (qry)
    {
    case Create_Table:
        str_qry = "CREATE TABLE TB1("  \
                  "Averge               INT  ," \
                  "Accumulation         INT );";
        break;
    case INSERT_Operation:
        std::sprintf(buff,"INSERT INTO TB1(Averge,Accumulation) VALUES (%d,%d);",Averge, Accumulation);
        str_qry = std::string(buff);
        break;
    case SELECT_Operation:
        str_qry = "SELECT * from TB1";
        break;
    default:
    //should throw exception
        break;
    }

    ret = sqlite3_exec(this->db, str_qry.c_str() , callback, 0, &Err);

    if(ret != SQLITE_OK) {
        std::cout << Err << "\n";
        sqlite3_free(Err);
    }


    return ret == SQLITE_OK; // return true on execute qry on data base 
}

#ifdef DataBase_UNIT_TEST
bool DataBase_unitTest() {
    std::string str("Test.db");
    DataBase d(str);

    if(d.Open()) {
        std::cout << "create and open success\n";
        if(d.ExecuteQry(Create_Table, NULL , NULL)) {
            std::cout << "create tble success\n";
            if(d.ExecuteQry(INSERT_Operation, 26 , 5)) {
                std::cout << "insert inside tble success\n";
                    if(d.ExecuteQry(INSERT_Operation, 40 , 9)) {
                        std::cout << "insert inside tble success\n";
                        if(d.ExecuteQry(SELECT_Operation,NULL,NULL)) {
                            std::cout << "SELECT_Operation from tble success\n";
                            return true;
                        }
                }
            }
        }
    }
    return false;
}
#endif