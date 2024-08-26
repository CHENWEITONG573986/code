#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // vector容器构造
    vector<int> v1; // 默认无参构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 通过区间的方式构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个elem方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

void test02()
{
    // vector尾插
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    printVector(v1);

    // vector尾删
    v1.pop_back();
    printVector(v1);

    // vector插入
    v1.insert(v1.begin(), 100);
    printVector(v1);

    // vector删除
    v1.erase(v1.begin());
    printVector(v1);

    // vector清空
    v1.clear();
    printVector(v1);

}

void test03()
{
    vector<int> v;
    int *p = NULL;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = v.begin();
    p = &v[0];
    cout << "it = " << typeid(it).name() << endl;
    cout << "p = " << typeid(float**).name() << endl;
}

int main()
{
    test01();
    test03();
    return 0;
}