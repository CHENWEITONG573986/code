#include "manager.h"

Manager::Manager()
{
}
Manager::Manager(string name, string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->initVector();
}
void Manager::openMenu()
{
    cout << "Manager: " << this->m_Name << " Login" << endl;
    cout << "1.addPerson" << endl;
    cout << "2.showPerson" << endl;
    cout << "3.showComputer" << endl;
    cout << "4.clearFile" << endl;
    cout << "0.Sign out" << endl;
    cout << "Please Enter your select:";
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
    while (true)
    {
        cout << "Please Enter your ID:";
        cin >> id;
        bool ret = this->cheakRepeak(id, select);
        if (ret)
            cout << "ID Repeat!!!" << endl;
        else
            break;
    }
    cout << "Please Enter your name:";
    cin >> name;
    cout << "Please Enter your pwd:";
    cin >> pwd;
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Add successful" << endl;
    this->initVector();
    system("pause");
    system("cls");
    ofs.close();
}

void printStudent(Student &s)
{
    cout << "ID:" << s.m_ID << " Name:" << s.m_Name << " Pwd:" << s.m_Pwd << endl;
}

void printTeacher(Teacher &t)
{
    cout << "ID:" << t.m_empId << " Name:" << t.m_Name << " Pwd:" << t.m_Pwd << endl;
}

void Manager::showPerson()
{
    cout << "Student--------" << endl;
    for_each(vStu.begin(), vStu.end(), printStudent);
    cout << endl;
    cout << "Teacher--------" << endl;
    for_each(vTea.begin(), vTea.end(), printTeacher);
}

void printComputerRoom(ComputerRoom &c)
{
    cout << "ID:" << c.m_ComId << " MaxNum:" << c.m_MaxNum << endl;
}

void Manager::showComputer()
{
    for_each(vCom.begin(), vCom.end(), printComputerRoom);
    cout << endl;
}

void Manager::clearFile()
{
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "Cleared successfully" << endl;
    system("pause");
    system("cls");
}

void Manager::initVector()
{
    vStu.clear();
    vTea.clear();
    vCom.clear();
    ifstream ifs;
    // Student
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "File Failed to open" << endl;
        return;
    }
    Student s;
    while (ifs >> s.m_ID && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }
    cout << "Student number: " << vStu.size() << endl;
    ifs.close();
    // Teacher
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "File Failed to open" << endl;
        return;
    }
    Teacher t;
    while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }
    cout << "Teacher number: " << vTea.size() << endl;
    ifs.close();
    // ComputerRoom
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "File Failed to open" << endl;
        return;
    }
    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
    {
        vCom.push_back(com);
    }
    cout << "ComputerRoom number: " << vCom.size() << endl;
    ifs.close();
}

bool Manager::cheakRepeak(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
            if (id == it->m_ID)
                return true;
    }
    else
    {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
            if (id == it->m_empId)
                return true;
    }
    return false;
}