#ifndef HEADER_5_3_COMPLEX_1_H
#define HEADER_5_3_COMPLEX_1_H

#include<iostream>
using namespace std;

class Complex
{
private:
    double r,i;

public:

    Complex(double x=0, double y=0): r(x),i(y){cout<<"r="<<r<<" i="<<i<<endl;};

    Complex(const Complex &c): r(c.r),i(c.i){};

    Complex add(const Complex &c);

    Complex sub(const Complex &c);

    void display();

    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);

    friend ostream& operator <<(ostream& out_put, const Complex &c);  //ÖØÔØÊäÈëÔËËã·û
    friend istream& operator >>(istream& in_put, Complex &c);



};

#endif // 5_1_COMPLEX_1_H
