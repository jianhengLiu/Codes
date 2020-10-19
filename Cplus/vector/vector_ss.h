#ifndef VECTOR_SS_H
#define VECTOR_SS_H

#include<iostream>

using namespace std;

template<class T>
class vector_ss
{
private:
    int v_size;//记录当前数组大小
    T* buf; //存放数组空间首地址

public:
    void push_back(T t)
    {
        if((sizeof(buf)<v_size+1)||(sizeof(buf)==0))
        {
            T* temp = buf;
            buf = new T[v_size+1];
            for (int i=0;i<v_size;i++)
              buf[i] = temp[i];
            delete []temp;
        }
        buf[v_size] = t;
        v_size++;
    };//在数组末尾插入元素

    T pop_back()
    {
        buf[v_size-1] = 0;
        v_size--;
        return buf[v_size];
    };//删除并返回末尾元素

    T front()
    {
        return buf[0];
    };//返回数组首元素

    void clear()
    {
        delete []buf;
        buf = new T[0];
        v_size = 0;
    };//清空数组

    bool empty()
    {
        if (v_size == 0)
            return 1;
        else
            return 0;
    };//返回数组是否为空

    void insert(int pos,T data)
    {
        v_size++;
        if((sizeof(buf)<v_size)||(sizeof(buf)==0))
        {
            T* temp = buf;
            buf = new T[v_size];
            for (int i=0;i<v_size;i++)
              buf[i] = temp[i];
            delete []temp;
        }
        for (int i = v_size-1;i>=pos-1;i--)
        {
            buf[i] = buf[i-1];
        }
        buf[pos-1] = data;
    };//在数组的第pos个位置插入data

    void erase(int pos)
    {
        v_size--;
        for (int i = pos-1;i<v_size;i++)
        {
            buf[i] = buf[i+1];
        }
    };//删除pos位置的数据

    void erase(int begin, int end)
    {
        v_size -= end - begin + 1;
        for (int i = begin -1;i<v_size;i++)
        {
            buf[i] = buf[i+end-begin+1];
        }
    };//删除从begin位置到end位置的数据

    const int& size() const {return v_size;};//返回数组的大小

    const vector_ss& operator=(const vector_ss & v)
    {
        v_size = v.size();
        if((sizeof(buf)<v_size)||(sizeof(buf)==0))
        {
            T* temp = buf;
            buf = new T[v_size];
            for (int i=0;i<v_size;i++)
              buf[i] = temp[i];
            delete []temp;
        }
        for (int i=0;i<v_size;i++)
        {
            buf[i] = v[i];
        }
    };//重载幅值函数

    const T& operator()(int i) const {return buf[i];};//重载()
    T& operator[](int n){return buf[n];};//重载[]
    const T& operator[](int n) const {return buf[n];};  //重载[]

    void display()
    {
        //cout<<v_size<<endl;
        for(int i=0;i<v_size;i++)
            cout<<buf[i]<<" ";
        cout<<endl;
    };

public:
    vector_ss()
    {
      buf = new T[0];
      v_size = 0;
    };//构造函数
    vector_ss(int n)
    {
      buf = new T[n];
      v_size = n;
    };//构造函数，产生一个大小为n的数组
    vector_ss(int n, T t)
    {
      buf = new T[n];
      v_size = n;
      for (int i=0;i<n;i++)
          buf[i] = t;
    };//构造函数，产生一个大小为n的数组，且每个元素均为t
    vector_ss(const vector_ss &v)
    {
      v_size = v.size();
      buf = new T[v_size];
      for(int i=0;i<v_size;i++)
      {
        buf[i] = v[i];v_size = v.size();
      }
    };//拷贝构造函数
    vector_ss(const vector_ss &v, int start, int end)
    {
        v_size = end + 1 - start;
        buf = new T[v_size];
        for(int i=0;i<v_size;i++)
            buf[i] = v[start-1+i];
    };
    //拷贝构造函数，数组元素为v的start位置到end位置的元素
    ~vector_ss()
    {
        delete []buf;
        //cout<<"析构完成"<<endl;
    };//析构函数
    };
#endif // VECTOR_SS_H

