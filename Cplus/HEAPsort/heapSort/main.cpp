#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swap1(T &a, T &b)
{
    T s;
    s = a;
    a = b;
    b = s;
}

template <typename T>
void insert_i(T a[], int length)
{
    int n = 2*length+1;
    if ((a[length]<a[n])&&(n<6)&&(n>=0))
    {
        swap1(a[length],a[n]);
        cout<<n<<" : ";
        for (int t = 0; t<6; t++)
        {
            cout<<" "<<a[t]<<" ";
        }
        cout<<endl;
        insert_i(a,(length-1)/2);
    }
    n++;
    if ((a[length]<a[n])&&(n<6)&&(n>=0))
    {
        swap1(a[length],a[n]);
        cout<<n<<" : ";
        for (int t = 0; t<6; t++)
        {
            cout<<" "<<a[t]<<" ";
        }
        cout<<endl;
        insert_i(a,(length-1)/2);
    }
}

template <typename T>
void delete_max (T a[], int length)
{
    swap1(a[0],a[length]);
    for(int i = 0; i<(length-1)/2; i++)
    {
        insert_i(a,i);
    }
}

template <typename T>
void heapSort (T a[],int n)
{
    cout<<"0"<<" : ";
    for (int t = 0; t<n; t++)
    {
        cout<<" "<<a[t]<<" ";
    }
    cout<<endl;

    cout<<"========================="<<endl;
    cout<<"通过插入过程实现建立堆"<<endl;
    cout<<"========================="<<endl;
    for(int i = 0; i<n; i++)
    {
        insert_i(a,i);
    }

    cout<<"========================="<<endl;
    cout<<"通过删除过程实现排序"<<endl;
    cout<<"========================="<<endl;
    for (int i = n-1; i>=0; i--)
    {
        delete_max(a,i);
    }

    cout<<"排序结果为：";
    for (int t = 0; t<n; t++)
    {
        cout<<" "<<a[t]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n = 6;
    int a[6]= {1,4,5,3,2,8};
    double d[6]= {1.4,4.3,2.5,3.7,9.2,0.8};
    char c[6]= {'c','d','r','a','y','b'};
    string s[6]= {"hello","yes","byebye","welcome","good","morning"};
    heapSort(a,n);
    heapSort(d,n);
    heapSort(c,n);
    //heapSort(s,n);
    return 0;
}
