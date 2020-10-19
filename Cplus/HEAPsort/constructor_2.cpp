#include <iostream>
#include <string>

using namespace std;

//���캯��������Ĭ�ϲ���

class point
{
public:
    int x;
    int y;

public:

    point()
    {
        x=0;
        y=0;
        cout<<"None parameter constructor"<<endl;
    }

    point(int a)
    {
        x=a;
        y=0;
        cout<<"One parameter constructor"<<endl;
    }

    point(int a/*=0*/, int b/*=0*/) //����ȥ��ע�ͺ󿴱������Լ���������кβ�ͬ
    {
        x=a;
        y=b;
        cout<<"Two parameters constructor"<<endl;
    }

    ~point()
    {
        cout<<"X="<<x<<" Y="<<y<<" Bye Bye"<<endl;

    }

    void set_point(int a, int b)
    {
        x=a;y=b;
    }

    void display_point()
    {
        cout<<"X="<<x<<" Y="<<y<<endl;
    }
};

int main()
{
    point p1;
    point p2(1);
    point p3(2,3);

    return 0;
}
