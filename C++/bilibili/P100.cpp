#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    // 属性
    string name;
    int ID;
    // 行为
    void assignment()
    {
        cin >> name >> ID;
    }
    void display()
    {
        cout << name << " " << ID << endl;
    }
};

int main()
{
    student s1, s2;
    s1.assignment();
    s1.display();
    s2.assignment();
    s2.display();
    s1.display();
    return 0;
}