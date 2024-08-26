#include<iostream>
using namespace std;
int main()
{
    int arr[9]={10,30,40,70,20,50,80,60,90},i,j,temp;
    for(i=0;i<8;i++)
        for(j=0;j<8-i;j++)
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
    for(i=0;i<9;i++)
        cout << arr[i] << endl;
    system("pause");
    return 0;
}