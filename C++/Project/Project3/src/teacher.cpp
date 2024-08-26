#include "teacher.h"

Teacher::Teacher()
{
}
Teacher::Teacher(int empId, string name, string pwd)
{
}
Teacher::~Teacher()
{
}
void Teacher::openMenu()
{
    cout << "Teacher: " << this->m_Name << "Login" << endl;
    cout << "1.showAllOrder" << endl;
    cout << "2.vaildOrder" << endl;
    cout << "3.showAllOrder" << endl;
    cout << "4.cancelOrder" << endl;
    cout << "0.Sign out" << endl;
}
void Teacher::showAllOrder()
{
}
void Teacher::vaildOrder()
{
}