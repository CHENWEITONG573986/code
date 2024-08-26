#include<iostream>
#include<string>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5},i,size,ARR[5];
    size=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<size;i++)
    {
        ARR[size-1-i]=arr[i];
    }
    for(i=0;i<size;i++)
        cout << ARR[i] << " ";
    system("pause");
    return 0;
}