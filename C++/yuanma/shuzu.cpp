#include<iostream>
#include<string>
using namespace std;
int main()
{
    int grades[3][3]={{90,90,90},{80,80,80},{70,70,70}},i,j,Score[3]={0,0,0};
    string name[3]={"张三","李四","王五"};
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            Score[i]+=grades[i][j];
        }
        cout << name[i] << Score[i] << endl;
    }
    system("pause");
    return 0;
}