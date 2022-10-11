#include "Average.h"

#ifdef Averge_unit_test
#include <iostream>
#endif

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


#ifdef Averge_unit_test
void Averge_UnitTest() {
    int samples = 5;
    std::vector<int> Values{1,2,3,4,5};

    Average average(samples);

    if(average.Calculate(Values) == 3) {
        std::cout << "Test Pass\n";
    }
    else {
        std::cout << "Test Fail\n";
    }
}
#endif