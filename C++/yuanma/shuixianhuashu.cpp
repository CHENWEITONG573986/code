#include<iostream>
using namespace std;
int main()
{
    int a=100,j,k,l;
    do{
        j=a/100;
        k=(a/10)%10;
        l=a%10;
        if(j*j*j+k*k*k+l*l*l==a)
            cout << a << endl;
        a++;
    }while(a<1000);
    system("pause");
    return 0;
}