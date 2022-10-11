#ifndef _Averge_H_
#define _Averge_H_

#include <vector>

#define Averge_unit_test 3
class Average
{
private:
    int samples;
public:
    Average(int n);
    ~Average();
    int Calculate(std::vector<int> &Values) const;
};

#ifdef Averge_unit_test
void Averge_UnitTest();
#endif

#endif //_Averge_H_