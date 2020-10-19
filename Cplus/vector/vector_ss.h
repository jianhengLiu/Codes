#ifndef VECTOR_SS_H
#define VECTOR_SS_H

#include<iostream>

using namespace std;

template<class T>
class vector_ss
{
private:
    int v_size;//��¼��ǰ�����С
    T* buf; //�������ռ��׵�ַ

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
    };//������ĩβ����Ԫ��

    T pop_back()
    {
        buf[v_size-1] = 0;
        v_size--;
        return buf[v_size];
    };//ɾ��������ĩβԪ��

    T front()
    {
        return buf[0];
    };//����������Ԫ��

    void clear()
    {
        delete []buf;
        buf = new T[0];
        v_size = 0;
    };//�������

    bool empty()
    {
        if (v_size == 0)
            return 1;
        else
            return 0;
    };//���������Ƿ�Ϊ��

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
    };//������ĵ�pos��λ�ò���data

    void erase(int pos)
    {
        v_size--;
        for (int i = pos-1;i<v_size;i++)
        {
            buf[i] = buf[i+1];
        }
    };//ɾ��posλ�õ�����

    void erase(int begin, int end)
    {
        v_size -= end - begin + 1;
        for (int i = begin -1;i<v_size;i++)
        {
            buf[i] = buf[i+end-begin+1];
        }
    };//ɾ����beginλ�õ�endλ�õ�����

    const int& size() const {return v_size;};//��������Ĵ�С

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
    };//���ط�ֵ����

    const T& operator()(int i) const {return buf[i];};//����()
    T& operator[](int n){return buf[n];};//����[]
    const T& operator[](int n) const {return buf[n];};  //����[]

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
    };//���캯��
    vector_ss(int n)
    {
      buf = new T[n];
      v_size = n;
    };//���캯��������һ����СΪn������
    vector_ss(int n, T t)
    {
      buf = new T[n];
      v_size = n;
      for (int i=0;i<n;i++)
          buf[i] = t;
    };//���캯��������һ����СΪn�����飬��ÿ��Ԫ�ؾ�Ϊt
    vector_ss(const vector_ss &v)
    {
      v_size = v.size();
      buf = new T[v_size];
      for(int i=0;i<v_size;i++)
      {
        buf[i] = v[i];v_size = v.size();
      }
    };//�������캯��
    vector_ss(const vector_ss &v, int start, int end)
    {
        v_size = end + 1 - start;
        buf = new T[v_size];
        for(int i=0;i<v_size;i++)
            buf[i] = v[start-1+i];
    };
    //�������캯��������Ԫ��Ϊv��startλ�õ�endλ�õ�Ԫ��
    ~vector_ss()
    {
        delete []buf;
        //cout<<"�������"<<endl;
    };//��������
    };
#endif // VECTOR_SS_H

