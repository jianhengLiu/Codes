#include <iostream>
#include <string>

//构造函数与析构函数的调用顺序，以及内存空间的释放与分配
//拷贝构造函数

using namespace std;

class point
{
private:
    int *c;

public:
    point(int a=0)
    {
        c=new int(a);
        cout<<"Point("<<*c<<") Constructor"<<endl;
    }

    ~point()
    {
        cout<<"Point("<<*c<<")"<<"Bye Bye"<<endl;
        if (c)
            delete c;
    }

    point(const point &p)
    {
        c=new int(*p.c);
        cout<<"Point("<<*c<<") Copy Constructor"<<endl;
    }

    void set_point(int a)
    {
        *c=a;
    }

    void display_point()
    {
        cout<<"*C="<<*c<<endl;
    }
};

void test()
{

}

int main()
{
    //运行程序，查看构造函数与析构函数的执行顺序，以及被调用的构造函数是哪个
    point p1(1);
    point p2=p1; //等同于point p2(p1);
    //p2.set_point(2); //运行本条语句，查看析构函数的输出有什么变化，体会初始化时候的=与语句中的=的区别。
    {

        point p3(3);
        point p4;
        p4=p3;
        //p4.set_point(4); //运行本条语句，查看析构函数的输出有什么变化，体会初始化时候的=与语句中的=的区别。
    }



    return 0;
}
