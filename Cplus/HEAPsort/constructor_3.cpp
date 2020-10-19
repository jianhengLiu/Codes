#include <iostream>
#include <string>

using namespace std;

//������

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

    //�����������д��룬�鿴�����������Ϣ
    //p3.set_point(1,2);
    //p3.display_point(); //����������崦��ע�ͣ������б��д��룬�鿴���

    return 0;
}
