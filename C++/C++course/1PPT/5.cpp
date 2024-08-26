#include <iostream>
using namespace std;
class Student // 声明一个类，类名为Student
{
private:           // 以下为类中的私有部分
    int num;       // 私有变量num
    int score;     // 私有变量score
public:            // 以下为类中公有部分
    void setdata() // 定义公有函数setdata
    {
        cin >> num;
        cin >> score;
    }
    void display() // 定义公有函数display
    {
        cout << "num=" << num << endl;
        cout << "score=" << score << endl;
    }
};         // 类的声明结束
int main() // 主函数首部
{
    Student stud1, stud2; // 定义stud1和stud2为Student类的变量，称为对象
    stud1.setdata();      // 调用对象stud1的setdata函数
    stud2.setdata();      // 调用对象stud2的setdata函数
    stud1.display();      // 调用对象stud1的display函数
    stud2.display();      // 调用对象stud1的display函数
    return 0;
}
