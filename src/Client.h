#ifndef _Client_H_
#define _Client_H_

#include "Average.h"
#include "COMM_MEDIA.h"
#include "Accumulation.h"
#include <vector>
#include <string>
#include "DataBase.h"
class Client
{
private:
    DataBase d;
    COMM_MEDIA ch;
    Average average;
    Accumulation accumulation;
    int counter;
    std::vector<int> values;
    int avg;
    int accumul;
    std::string RawData;
    bool Ready;
public:
    Client();
    ~Client();
    bool waitRecv();
    void updateResults();
    void save();
};



#endif //_Client_H_