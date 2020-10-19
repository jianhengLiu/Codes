#include<iostream>

using namespace std;

int operator+ (int a, int b)
{
    return a+b;
}

int main()
{
    int a=1;
    int b=1;

    cout<<"a="<<a<<" b="<<b<<endl;

    if (1 || a++ || b++){}

    cout<<"a="<<a<<" b="<<b<<endl;

    if (0 && a++ && b++){}

    cout<<"a="<<a<<" b="<<b<<endl;

    if (a++ || b++){}

    cout<<"a="<<a<<" b="<<b<<endl;

    if (a++ && b++){}

    cout<<"a="<<a<<" b="<<b<<endl;

    return 0;
}
