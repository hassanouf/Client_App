#ifndef _Accumulation_H_
#define _Accumulation_H_

#include <vector>

class Accumulation
{
private:
    int samples;
public:
    Accumulation(int n);
    ~Accumulation();
    int Calculate(std::vector<int> &Values) const;
};

#endif //_Accumulation_H_