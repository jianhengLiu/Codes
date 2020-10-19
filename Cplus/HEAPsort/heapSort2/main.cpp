#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swap1(T &a, T &b) //交换函数
{
    T s;
    s = a;
    a = b;
    b = s;
}

template <typename T>
void insert_i(T a[],int length) //建立堆函数
{
    if ((a[length])>(a[(length-1)/2]))  //子与父比较
    {
        swap1(a[length],a[(length-1)/2]);
        insert_i(a,(length-1)/2 );   //交换后进行复查
    }
}

template <typename T>
void delete_max (T a[], int length)  //删除最大值函数
{
    swap1(a[0],a[length]);
    for (int i=0; i<length-1; i++)
        insert_i(a,length-1-i);
}

template <typename T>
void heapSort (T a[],int n) //堆排序函数
{
    cout<<"========================="<<endl;
    cout<<"通过插入过程实现建立堆"<<endl;
    cout<<"========================="<<endl;
    for(int i = 0; i<n; i++)  //建立堆
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
    for (int i = n-1; i>0; i--)  //依次删除最大值
    {
        delete_max(a,i);
        cout<<5-i<<" : ";
        for (int t = 0; t<n; t++)
        {
            cout<<" "<<a[t]<<" ";
        }
        cout<<endl;
    }

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
