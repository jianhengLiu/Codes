#include <iostream>

using namespace std;

//�����������Ը�������Ϊ�����������к������鿴��������ʾ
void f1(int x){};
void f2(int const x){};
void f3(int &x){};
void f4(int const &x){};
void f5(int *x){};
void f6(int const *x){};
void f7(int* const x){};


int main()
{
    //������򲢸��ݱ������Ĵ�����ʾ���޸ĳ��������﷨���������ֶ����ʹ�÷���
    int a1;
    int const a2;//=a1;

    // �ֱ�b1��b2��ʼ��Ϊa1��a2�����ã�������������ʾ
    int &b1;
    int const &b2; //��b2��ʼ��Ϊa1�����ã����Ըı�a1��ֵ�Լ�b1��ֵ��������鿴���н��

    // �ֱ�����ָ���ʼ��Ϊa1��a2�ĵ�ַ��������������ʾ
    int* p1;
    int const *p2; //��p2��ʼ��Ϊa1�ĵ�ַ�����Ըı�a1��ֵ�Լ�p2��ֵ��������鿴���н��
    int* const p3;  //��p3�ֱ��ʼ��Ϊa1��a2�ĵ�ַ���鿴����������ʾ

    //���Խ�const�������ڵȺŵ���ߣ��������������
    a2=a1;

    return 0;
}
