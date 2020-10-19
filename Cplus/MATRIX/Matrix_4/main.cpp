#include <iostream>
#include "MATRIX_4.h"

using namespace std;

int main()
{
    double det;
    double m[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    double test[4][4]={{0,2,0,1},{3,3,2,1},{3,2,4,0},{2,2,1,1}};

    Matrix_4x4 a;
    Matrix_4x4 b(a);
    Matrix_4x4 c(m);
    Matrix_4x4 d;
    Matrix_4x4 t(test);
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            d[i][j]=-i*4-j;
    }

    cout<<"a : "<<a<<endl;
    cout<<"b(a) : "<<b<<endl;
    cout<<"c(m) : "<<c<<endl;
    cout<<"d : "<<d<<endl;

    d=a+c;
    cout<<"d=a+c : "<<d<<endl;

    d=d-a;
    cout<<"d=d-a : "<<d<<endl;

    d=a*c;
    cout<<"d=a*c : "<<d<<endl;

    det=c.det();
    cout<<"det = "<<det<<endl;

    cout<<"t : "<<t<<endl;
    t=t.inverse();
    cout<<"t=t.inverse() : "<<t<<endl;

    d=c.transpose();
    cout<<"d=c.transpose() : "<<d<<endl<<"c: "<<c;

    return 0;
}
