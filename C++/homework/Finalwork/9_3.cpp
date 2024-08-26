#include <iostream>
using namespace std;
class Teacher
{
protected:
    int time;

public:
    Teacher(){};
    Teacher(int time) : time(time){};
    virtual int getSalary() = 0;
};
class Professor : public Teacher
{
public:
    Professor(){};
    Professor(int time) : Teacher(time){};
    int getSalary() override;
};
class AssociateProfessor : public Teacher
{
public:
    AssociateProfessor(){};
    AssociateProfessor(int time) : Teacher(time){};
    int getSalary() override;
};
class Lecturer : public Teacher
{
public:
    Lecturer(){};
    Lecturer(int time) : Teacher(time){};
    int getSalary() override;
};
int Professor::getSalary()
{
    return 5000 + 50 * time;
}
int AssociateProfessor::getSalary()
{
    return 3000 + 30 * time;
}
int Lecturer::getSalary()
{
    return 2000 + 20 * time;
}
int main()
{
    Teacher *T[3];
    T[0] = new Professor(100);
    T[1] = new AssociateProfessor(100);
    T[2] = new Lecturer(100);
    cout << T[0]->getSalary() << endl;
    cout << T[1]->getSalary() << endl;
    cout << T[2]->getSalary() << endl;
    system("pause");
    return 0;
}