#include "Client.h"
#include <iostream>
#include <sstream>

const char Buff[10] = "Client.db";

Client::Client() : ch(TCPSocket) , average(5) , accumulation(5) ,
d(std::string(Buff))
{
    this->counter = 0;
    this->avg = 0;
    this->accumul = 0;
    this->Ready = false;

    ch.Open(TCPSocket , "172.18.112.1" , 30000);
    d.Open();
    d.ExecuteQry(Create_Table, 0 , 0);
}

Client::~Client()
{
    ch.Close(TCPSocket);
    d.Close();
}

bool Client::waitRecv() {
    return ch.Recieve(TCPSocket,this->RawData);
}
void Client::updateResults() {
    int num = 0;
    std::stringstream str(this->RawData);
    str >> num;
    std::cout << "values.push_back(num)" << num << "\n";
    values.push_back(num);
    this->counter++;
    std::cout << "this->counter++;" << this->counter << "\n";

    if(this->counter >= 5) {
        std::cout << "Ready" << "\n";
        this->Ready = true;
        this->counter = 0;
    }
}

void Client::save() {
    if (this->Ready)
    {
        this->avg = this->average.Calculate(this->values) ;
        this->accumul = this->accumulation.Calculate(this->values);
        std::cout << this->avg << "\n";
        std::cout << this->accumul << "\n";
        d.ExecuteQry(INSERT_Operation, this->avg , this->accumul);
        this->values.clear();
        this->Ready = false;
    }
}