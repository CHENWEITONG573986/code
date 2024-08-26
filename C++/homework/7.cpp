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
    Worker work1;
    work1.num=1;work1.name="张三";work1.salary=4000;
    work1.show();
    system("pause");
    return 0;
}