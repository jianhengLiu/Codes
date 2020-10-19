#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int c=0;

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
        c++;
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
             c++;
            a[i]=a[n];
            delete_max(a,n,length);
        }
        else
        {
             c++;
            a[i]=a[n-1];
            delete_max(a,n-1,length);
        }
    }
    else
    {
         c++;
        a[i]=a[length];
        insert_i(a,i);
    }

}

template <typename T>
void heapSort (T a[],int n)
{
    for(int i = 0; i<n; i++)
    {
        insert_i(a,i);
    }
    for (int i = n-1; i>=0; i--)
    {
        T s=a[0];
        delete_max(a,0,i);
        a[i]=s;
    }
}

int main()
{
    int n;
    for(n=100; n<=4000; n=n+100)
    {
        int *a=new int[n];
        for (int i= 0; i<n; i++)
            a[i]=rand();
        c = 0;
        heapSort(a,n);
        cout<<"========================="<<endl;
        cout<<"n: "<<n;
        cout<<" Compare : "<<c<<endl;
        cout<<"========================="<<endl;
        delete[] a;
    }
    return 0;
}
