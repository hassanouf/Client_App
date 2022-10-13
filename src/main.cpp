#include "Client.h"
#include <iostream>

int main(int argc, char** argv) {

    std::cout << "Hello,Dell\n";
    
    Client client(std::string(argv[1]) , std::stoi(std::string(argv[2])));

    while (1)
    {
        if(client.waitRecv() == Success) {
            client.updateResults();
            client.save();
        }
    }
    return 0;
}