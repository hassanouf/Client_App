#ifndef _Accumulation_H_
#define _Accumulation_H_

#include <vector>

#define Accumulation_unit_test 3
class Accumulation
{
private:
    int samples;
public:
    Accumulation(int n);
    ~Accumulation();
    int Calculate(std::vector<int> &Values) const;
};

#ifdef Accumulation_unit_test
void Accumulation_UnitTest();
#endif

#endif //_Accumulation_H_