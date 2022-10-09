#ifndef _Averge_H_
#define _Averge_H_

#include <vector>


class Average
{
private:
    int samples;
public:
    Average(int n);
    ~Average();
    int Calculate(std::vector<int> &Values) const;
};



#endif //_Averge_H_