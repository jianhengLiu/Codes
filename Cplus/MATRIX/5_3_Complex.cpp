#include<iostream>
#include "5_3_Complex.h"
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


Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex tmp_c;

    tmp_c.i=c1.i+c2.i;
    tmp_c.r=c1.r+c2.r;

    return tmp_c;
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    Complex tmp_c;

    tmp_c.i=c1.i-c2.i;
    tmp_c.r=c1.r-c2.r;

    return tmp_c;
}



ostream& operator <<(ostream& out_put, const Complex &c) //ÖØÔØÊäÈëÔËËã·û
{
    out_put<<c.r<<"+"<<c.i<<"i";

    return out_put;
}

istream& operator >>(istream& in_put, Complex &c)
{
    in_put>>c.r>>c.i;

    return in_put;
}
