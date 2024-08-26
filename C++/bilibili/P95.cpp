#include<iostream>
using namespace std;
//声明和定义只能有一个有默认值
//int func(int a,int b=20,int c=30);X
//如果有默认值，那从左往右都必须有默认值
//int func(int a=10,int b,int c)X
int func(int a,int b=20,int c=30)
{
    return a+b+c;
}

int main()
{
    cout << func(10) << endl;
    cout << func(10,30) << endl;
    cout << func(10,30,40) << endl;
    system("pause");
    return 0;
}