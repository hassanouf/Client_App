#include "COMM_MEDIA.h"
#include <iostream>

int main() {

    std::cout << "Hello,Dell";
    
    if(COMM_MEDIA_UnitTest()) {
        std::cout << "Comm Media test pass\n";
    }
    else {
        std::cout << "Comm Media test fail\n";
    }

    return 0;
}