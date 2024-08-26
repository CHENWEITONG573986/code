#include<iostream>
using namespace std;
//1.值传递
void zhi(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
//2.地址传递
void dizhi(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//3.引用传递
void yinyong(int& a,int& b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a=10;
    int b=20;
    zhi(a,b);
    cout << "值传递" << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    a=10;
    b=20;
    dizhi(&a,&b);
    cout << "地址传递" << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    a=10;
    b=20;
    yinyong(a,b);
    cout << "引用传递" << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    system("pause");
    return 0;
}