#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
    int num;
    string name;
    float salary;
    void show()
    {
        cout << "num:" << num << endl;
        cout << "name:" << name << endl;
        cout << "salary:" << salary << endl;
    }
};
int main()
{
    Worker work1,*p;
    p=&work1;
    p->num=1;p->name="张三";p->salary=4000;
    p->show();
    system("pause");
    return 0;
}