#include "Client.h"
#include <iostream>

int main() {

    std::cout << "Hello,Dell\n";
    
    Client client;

    while (1)
    {
        if(client.waitRecv() == Success) {
            client.updateResults();
            client.save();
        }
    }
    return 0;
}