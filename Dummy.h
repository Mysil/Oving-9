#pragma once
#include <utility>
using namespace std; 

class Dummy {
public:

    int *num;
    Dummy() 
    {
        num = new int{0};
    }
    Dummy(const Dummy& d) : num{nullptr}
    {
        this->num = new int{};
        *num = *d.num;
    }
    ~Dummy() 
    {
        delete num;
    }
    Dummy& operator=(Dummy rhs)
    {
        swap(num, rhs.num);
        return *this;
    }
};


void dummyTest(); 





