#include <iostream>
#include <string>

using namespace std;

//构造函数重载与默认参数

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

    point(int a/*=0*/, int b/*=0*/) //尝试去掉注释后看编译结果以及运行输出有何不同
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
