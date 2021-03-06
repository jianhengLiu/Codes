#include<iostream>
#include "5_2_Complex.h"
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


Complex Complex::operator+(const Complex &c)
{
    Complex tmp_c;

    tmp_c.i=i+c.i;
    tmp_c.r=r+c.r;

    return tmp_c;
}

Complex Complex::operator-(const Complex &c)
{
    Complex tmp_c;

    tmp_c.i=i-c.i;
    tmp_c.r=r-c.r;

    return tmp_c;
}



/*
ostream& operator <<(ostream& out_put, const Complex &c) //�������������
{
    out_put<<c.r<<"+"<<c.i<<"i";

    return out_put;
}

istream& operator >>(istream& in_put, Complex &c)
{
    in_put>>c.r>>c.i;

    return in_put;
}
*/
