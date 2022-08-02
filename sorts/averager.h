#ifndef AVERAGER_H
#define AVERAGER_H
#include <iostream>

using namespace std;

class averager
{

public:
    averager();
    void next_number(float value);
    std::size_t how_many_numbers() const { return count; }
    double average() const;
private:
    std::size_t count;
    double sum;
};

#endif // AVERAGER_H
