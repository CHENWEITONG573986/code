#include<iostream>
using namespace std;
int main()
{
    int arr[5]={300,350,400,200,250},i,temp;
    for(i=0;i<5;i++)
        if(arr[i]>arr[0])
            temp=i;
    cout << arr[temp] << endl;
    system("pause");
    return 0;
}
