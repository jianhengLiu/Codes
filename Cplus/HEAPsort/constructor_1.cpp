#include <iostream>
#include <string>

//���캯�������������ĵ���˳���Լ��ڴ�ռ���ͷ������
//�������캯��

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
    //���г��򣬲鿴���캯��������������ִ��˳���Լ������õĹ��캯�����ĸ�
    point p1(1);
    point p2=p1; //��ͬ��point p2(p1);
    //p2.set_point(2); //���б�����䣬�鿴���������������ʲô�仯������ʼ��ʱ���=������е�=������
    {

        point p3(3);
        point p4;
        p4=p3;
        //p4.set_point(4); //���б�����䣬�鿴���������������ʲô�仯������ʼ��ʱ���=������е�=������
    }



    return 0;
}
