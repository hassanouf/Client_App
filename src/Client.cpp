#include "Client.h"
#include <iostream>
#include <sstream>

Client::Client() : ch(TCPSocket) , average(5) , accumulation(5) 
{
    this->counter = 0;
    //this->average = 0;
    //this->accumul = 0;
    this->Ready = false;

    ch.Open(TCPSocket , "172.18.112.1" , 30000);
}

Client::~Client()
{
    ch.Close(TCPSocket);
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
        std::cout << this->average.Calculate(this->values) << "\n";
        std::cout << this->accumulation.Calculate(this->values) << "\n";
        this->values.clear();
        this->Ready = false;
    }
}