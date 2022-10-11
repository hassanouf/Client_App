#include "Accumulation.h"

#ifdef Accumulation_unit_test
#include <iostream>
#endif

Accumulation::Accumulation(int n) : samples(n) {}


Accumulation::~Accumulation()
{
}

int Accumulation::Calculate(std::vector<int> &Values) const {
    int sum = 0;
    for(int i : Values) {
        sum += i;
    }
    return (sum);
}

#ifdef Accumulation_unit_test
void Accumulation_UnitTest() {
    int samples = 5;
    std::vector<int> Values{1,2,3,4,5};

    Accumulation accumulation(samples);

    if(accumulation.Calculate(Values) == 15) {
        std::cout << "Test Pass\n";
    }
    else {
        std::cout << "Test Fail\n";
    }
}
#endif