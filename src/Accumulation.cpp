#include "Accumulation.h"

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