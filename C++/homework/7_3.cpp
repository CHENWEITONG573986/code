#include <iostream>
using namespace std;
class Cat
{
public:
    static int num;
    static void getNum();
    Cat();
};
int Cat::num = 0;
Cat::Cat()
{
    this->num++;
}
void Cat::getNum()
{
    cout << "Cat类的个数为：" << num << endl;
}
int main()
{
    Cat c1,c2,c3,c4,c5;
    Cat::getNum();
}