#include<iostream>
#include<string>
using namespace std;

int cnt_compare=0;

void set_cnt()
{
    cnt_compare=0;
}

void display_cnt()
{
    cout<<" Compare : "<<cnt_compare<<endl<<"========================"<<endl;
}

/*�����ô��εķ�������һ��swap����*/
template <typename T>
void swap1(T &a,T &b)
{
    T tmp;
    tmp=a;
    a=b;
    b=tmp;
}

template <typename T>
void insert_i(T a[], int length)
{
    while (length>0)
    {
        int parent=(length-1)/2;

        if (a[parent]<a[length])
        {
            swap1(a[parent],a[length]);
            length=parent;

            cnt_compare++;//����Ƚϴ�����
        }
        else
            break;
    }
}

template <typename T>
void delete_max(T a[], int length)
{
    T tmp=a[0];
    int ind=0;

    while(1)
    {
        int left = 2*ind + 1;
        int right = 2*ind + 2;

        if(left>=length)
        {
            break;
        }
        else
        {
            int large=a[left]>a[right] ? left : right;
            a[ind]=a[large];
            ind=large;

            cnt_compare++; //����Ƚϴ���
        }
    }

    a[ind]=a[length];
    insert_i(a,ind);
    a[length]=tmp;
}


/*������*/
template <typename T>
void heapSort(T a[],int n)
{
    //ͨ���������ʵ�ֽ�����
    for (int i=0;i<n;i++)
        insert_i(a,i);

    //ͨ��ɾ������ʵ������"
    for (int i=n-1;i>0;i--)
        delete_max(a,i);
}

#include <stdlib.h>
int main()
{
    int n;

    for (n=100;n<=4000;n=n+100)
    {
        int *a=new int[n];
        for (int i=0;i<n;i++)
        {
            a[i]=rand();
        }
        cout<<"n: "<<n;
        set_cnt();  //������ֵ��0
        heapSort(a,n);
        display_cnt(); //�������ֵ

        delete[] a;
    }
    return 0;
}
