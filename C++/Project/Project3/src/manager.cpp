#include "manager.h"

Manager::Manager()
{
}
Manager::Manager(string name, string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;
}
void Manager::openMenu()
{
    cout << "Manager: " << this->m_Name << " Login" << endl;
    cout << "1.addPerson" << endl;
    cout << "2.showPerson" << endl;
    cout << "3.showComputer" << endl;
    cout << "4.clearFile" << endl;
    cout << "0.Sign out" << endl;
}
void Manager::addPerson()
{
    cout << "Please select a type" << endl;
    cout << "1.Student" << endl;
    cout << "2.Teacher" << endl;
    string fileName;
    ofstream ofs;
    int select;
    cin >> select;
    if (select == 1)
        fileName = STUDENT_FILE;
    else if (select == 2)
        fileName = TEACHER_FILE;
    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout << "Please Enter your ID:";
    cin >> id;
    cout << "Please Enter your name:";
    cin >> name;
    cout << "Please Enter your pwd:";
    cin >> pwd;
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Add successful" << endl;
    system("pause");
    system("cls");
    ofs.close();
}
void Manager::showPerson()
{
}
void Manager::showComputer()
{
}
void Manager::clearFile()
{
}