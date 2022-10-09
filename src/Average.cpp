#include "Average.h"

Average::Average(int n) : samples(n) {}

Average::~Average()
{
}

int Average::Calculate(std::vector<int> &Values) const {
    int sum = 0;
    for(int i : Values) {
        sum += i;
    }
    return (sum/this->samples);
}