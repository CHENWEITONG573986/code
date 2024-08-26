#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int num;
    string name;
    int scores1;
    int scores2;

public:
    Student()
    {
    }
    Student(int num, string name, int scores1, int scores2)
    {
        this->num = num;
        this->name = name;
        this->scores1 = scores1;
        this->scores2 = scores2;
    }
    ~Student()
    {
    }
    float FindAverage();
};
float Student::FindAverage()
{
    return (scores1 + scores2) / 2;
}
int main()   
{
    Student S(111, "成龙", 60, 80);
    cout << "平均成绩：" << S.FindAverage() << endl;
    system("pause");
    return 0;
}