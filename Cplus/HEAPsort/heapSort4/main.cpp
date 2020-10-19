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
void insert_i(T a[],int length)
{
    if ((a[length])>(a[(length-1)/2]))
    {
        swap1(a[length],a[(length-1)/2]);
        insert_i(a,(length-1)/2 );
    }

}

template <typename T>
void delete_max (T a[], int i, int length)
{
    int n=2*i+2;
    if(n<length)
    {
        if(a[n]>a[n-1])
        {
            a[i]=a[n];
            delete_max(a,n,length);
        }
        else
        {
            a[i]=a[n-1];
            delete_max(a,n-1,length);
        }
    }
    else
    {
        a[i]=a[length];
        insert_i(a,i);
    }

}

template <typename T>
void heapSort (T a[],int n)
{
    cout<<"========================="<<endl;
    cout<<"通过插入过程实现建立堆"<<endl;
    cout<<"========================="<<endl;
    for(int i = 0; i<n; i++)
    {
        insert_i(a,i);
        cout<<i<<" : ";
        for (int t = 0; t<n; t++)
        {
            cout<<" "<<a[t]<<" ";
        }
        cout<<endl;
    }
    cout<<"========================="<<endl;
    cout<<"通过删除过程实现排序"<<endl;
    cout<<"========================="<<endl;
    for (int i = n-1; i>=0; i--)
    {
        T s=a[0];
        delete_max(a,0,i);
        a[i]=s;
        cout<<5-i<<" : ";
        for (int t = 0; t<n; t++)
        {
            cout<<" "<<a[t]<<" ";
        }
        cout<<endl;
    }
    cout<<"========================="<<endl;
    cout<<"排序结果为：";
    for (int t = 0; t<n; t++)
    {
        cout<<" "<<a[t]<<" ";
    }
    cout<<endl;
    cout<<"========================="<<endl;
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
    heapSort(s,n);
    return 0;
}
