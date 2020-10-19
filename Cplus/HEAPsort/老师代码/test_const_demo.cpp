#include <iostream>
using namespace std;

class T
{
private:
    int a;

public:
    T(){a=1;}
    int const& get_data() const {return a;}
    void display() const {cout<<a<<endl;}
};

int main()
{
    T const t;

    t.get_data();
    t.display();

    return 0;
}
