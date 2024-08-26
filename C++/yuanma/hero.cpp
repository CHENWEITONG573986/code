#include<iostream>
#include<string>
using namespace std;
struct hero
{
    string name;
    int age;
    string gender;
};
int main()
{
    int i,j;
    hero temp;
    hero h[5]={ {"刘备",23,"男"},
                {"关羽",22,"男"},
                {"张飞",20,"男"},
                {"赵云",21,"男"},
                {"貂蝉",19,"女"}};
    int len=sizeof(h)/sizeof(h[0]);
    for(i=0;i<len-1;i++)
        for(j=0;j<len-1-i;j++)
        {
            if(h[j].age>h[j+1].age)
            {
                temp=h[j];
                h[j]=h[j+1];
                h[j+1]=temp;
            }
        }
    for(i=0;i<5;i++)
        cout << h[i].name << h[i].age  << h[i].gender << endl;
}