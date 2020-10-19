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
void delete_max (T a[], int length, int i)
{
    if ((a[2*length+1]>a[2*length+2])&&((2*length+1)<6)&&(a[length] > a[2*length+1]))
    {
        a[length] = a[2*length+1];
        delete_max(a,2*length+1,i);
    }

    if ((a[2*length+1]<=a[2*length+2])&&((2*length+2)<6)&&(a[length] > a[2*length+2]))
    {
        a[length] = a[2*length+2];
        delete_max(a,2*length+2,i);
    }
    if (((2*length+1)<6)&&((2*length+2)>5)&&(a[length] > a[2*length+1]))
        a[length] = a[i];
    else
        a[length] = a[i];
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
    cout<<"ͨ���������ʵ�ֽ�����"<<endl;
    cout<<"========================="<<endl;
    for(int i = 0; i<n; i++)
    {
        insert_i(a,i);
    }

    cout<<"========================="<<endl;
    cout<<"ͨ��ɾ������ʵ������"<<endl;
    cout<<"========================="<<endl;
    for (int i = n-1; i>=0; i--)
    {
        T s = a[0];
        delete_max(a,0,i);
        a[i] = s;
    }

    cout<<"������Ϊ��";
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
