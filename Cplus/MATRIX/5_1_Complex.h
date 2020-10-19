#ifndef HEADER_5_1_COMPLEX_1_H
#define HEADER_5_1_COMPLEX_1_H

class Complex
{
private:
    double r,i;

public:

    Complex(double x=0, double y=0): r(x),i(y){};

    Complex(const Complex &c): r(c.r),i(c.i){};

    Complex add(const Complex &c);

    Complex sub(const Complex &c);

    void display();

};

#endif // 5_1_COMPLEX_1_H
