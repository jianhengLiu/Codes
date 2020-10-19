#include<iostream>
#include "5_1_Complex.h"
using namespace std;

Complex Complex::add(const Complex &c)
{
    r+=c.r;
    i+=c.i;

    return *this;
}

Complex Complex::sub(const Complex &c)
{
    r-=c.r;
    i-=c.i;

    return *this;
}

void Complex::display()
{
    cout<<r<<"+"<<i<<"i"<<endl;
}
