#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
    Worker(){};
    Worker(int n, string name, float s);
    Worker(Worker &W);
    void show();
private:
    int num;
    string name;
    float salary;
};

Worker::Worker(int n,string namel,float s)
{
    num = n;
    name = namel;
    salary = s;
}

Worker::Worker(Worker &W)
{
    num = W.num;
    name = W.name;
    salary = W.salary;
}

void Worker::show()
{
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"salary:"<<salary<<endl;
}

int main()
{
    Worker work1(1,"张三",4000),work2(work1);
    work1.show();
    work2.show();
    system("pause");
    return 0;
}