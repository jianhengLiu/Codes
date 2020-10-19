#include<iostream>
//#include"5_1_Complex.cpp"
//#include"5_2_Complex.cpp"
#include"5_3_Complex.cpp"

using namespace std;

int main()
{

    Complex c1;
    Complex c2;
    Complex c3;

    cout<<"c1=";c1.display();
    cout<<"c2=";c2.display();
    cout<<"c3=";c3.display();

    c3.sub(c2);
    cout<<"c3.sub(c2)=";c3.display();

    cout<<"c1.add(c2)=";(c1.add(c2)).display();

    c1=c3+c2;
    cout<<"c1=c3+c2:";c1.display();

    cout<<"c3-c2=";(c3-c2).display();


    cout<<"Input c1:";
    cin>>c1;
    cout<<"c1 = "<<c1<<endl;

    cout<<"c1+2="<<c1+2<<endl;
    cout<<"2+c1="<<2+c1<<endl;

    return 0;
}
