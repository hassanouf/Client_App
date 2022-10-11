#include "Accumulation.h"
#include <bits/stdc++.h>

#ifdef Accumulation_unit_test
#include <iostream>
#endif

Accumulation::Accumulation(int n) : samples(n) {}


Accumulation::~Accumulation()
{
}

int Accumulation::Calculate(std::vector<int> &Values) const {
    int sum = 0;
    std::sort(Values.begin(), Values.end()); //ascending
    sum = Values[n-1] - Values[0];
    return (sum);
}

#ifdef Accumulation_unit_test
void Accumulation_UnitTest() {
    int samples = 5;
    std::vector<int> Values{4,2,5,1,3};

    Accumulation accumulation(samples);

    if(accumulation.Calculate(Values) == 4) {
        std::cout << "Test Pass\n";
    }
    else {
        std::cout << "Test Fail\n";
    }
}
#endif