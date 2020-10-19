#include <iostream>
#include <string>

using namespace std;

//常对象

class point
{
public:
    int x;
    int y;

public:


    point(int a=0, int b=0)
    {
        x=a;
        y=b;
        cout<<"Two parameters constructor"<<endl;
    }

    point(const point &p)
    {
        x=p.x;
        y=p.y;
        cout<<"Copy constructor"<<endl;
    }

    ~point()
    {
        cout<<"X="<<x<<" Y="<<y<<" Bye Bye"<<endl;

    }

    void set_point(int a, int b)
    {
        x=a;y=b;
    }

    void display_point() //const
    {
        cout<<"X="<<x<<" Y="<<y<<endl;
    }
};

int main()
{
    point p1(2,3);
    point p2=p1;
    const point p3=p1;

    //运行下列两行代码，查看编译器输出信息
    //p3.set_point(1,2);
    //p3.display_point(); //解除函数定义处的注释，再运行本行代码，查看输出

    return 0;
}
