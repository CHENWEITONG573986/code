#include "Student.h"

Student::Student()
{
}
Student::Student(int id, string name, string pwd)
{
}
Student::~Student()
{
}
void Student::openMenu()
{
    cout << "Student: " << this->m_Name << " Login" << endl;
    cout << "1.applyOrder" << endl;
    cout << "2.showMyOrder" << endl;
    cout << "3.showAllOrder" << endl;
    cout << "4.cancelOrder" << endl;
    cout << "0.Sign out" << endl;
}
void Student::applyOrder()
{
}
void Student::showMyOrder()
{
}
void Student::showAllOrder()
{
}
void Student::cancelOrder()
{
}