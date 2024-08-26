#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int id;
    string name;
    int scores;
    static int num;
    static int sum;

public:
    Student(){};
    Student(int id, string name, int scores) : id(id), name(name), scores(scores)
    {
        sum += scores;
        num++;
    };
    static float getAverage();
    ~Student(){};
};
int Student::sum = 0;
int Student::num = 0;
float Student::getAverage()
{
    return sum / num;
}
int main()
{
    Student S1(100, "陈", 90), S2(101, "沈", 80), S3(102, "刘", 70), S4(103, "郭", 100);
    cout << Student::getAverage() << endl;
    system("pause");
    return 0;
}