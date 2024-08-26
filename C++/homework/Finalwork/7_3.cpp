#include <iostream>
using namespace std;
class Cat
{
private:
    static int num;

public:
    Cat() { num++; };
    static int getNum();
    ~Cat(){};
};
int Cat::num = 0;
int Cat::getNum()
{
    return num;
}
int main()
{
    Cat c1, c2, c3, c4, c5, c6;
    cout << Cat::getNum() << endl;
    system("pause");
    return 0;
}