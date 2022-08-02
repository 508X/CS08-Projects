#include "averager.h"
#include <cassert>

averager::averager(){
    count = 0;
    sum = 0;
}
void averager::next_number(float value){
    ++count;
    sum+=value;
}
double averager::average() const{
    assert(how_many_numbers()>0);
    return sum/count;
}
