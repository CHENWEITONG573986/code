#include <iostream>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <fstream>
#include <string>
using namespace std;

void managerMenu(Identity *manager)
{
    while (true)
    {
        manager->openMenu();
        Manager *man = (Manager *)manager;
        int choice = 0;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Add Person" << endl;
            man->addPerson();
        }
        else if (choice == 2)
        {
            cout << "show Person" << endl;
            man->showPerson();
        }
        else if (choice == 3)
        {
            cout << "shoe Computer Room" << endl;
            man->showComputer();
        }
        else if (choice == 4)
        {
            cout << "ClearOrder" << endl;
            man->clearFile();
        }
        else
        {
            delete manager;
            cout << "Sign out" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void studentMenu(Identity *student)
{
    while (true)
    {
        student->openMenu();
        Student *stu = (Student *)student;
        int select = 0;
        cin >> select;
        if (select == 1)
        {
            stu->applyOrder();
        }
        else if (select == 2)
        {
            stu->showMyOrder();
        }
        else if (select == 3)
        {
            stu->showAllOrder();
        }
        else if (select == 4)
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            cout << "Sign out" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void teacherMenu(Identity *teacher)
{
    while (true)
    {
        teacher->openMenu();
        Teacher *tea = (Teacher *)teacher;
        int select = 0;
        cin >> select;
        if (select == 1)
        {
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            tea->vaildOrder();
        }
        else
        {
            delete teacher;
            cout << "Sign out" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void LoginIn(string fileName, int type)
{
    Identity *person = NULL;
    //
    ifstream ifs;
    ifs.open(fileName, ios::in);
    //
    if (!ifs.is_open())
    {
        cout << "File Error !!!" << endl;
        ifs.close();
        return;
    }
    //
    int id = 0;
    string name;
    string pwd;
    //
    if (type == 1 || type == 2)
    {
        cout << "Please enter your id:";
        cin >> id;
    }
    cout << "Please enter your name:";
    cin >> name;
    cout << "Please enter your pwd:";
    cin >> pwd;
    if (type == 1)
    {
        int f_Id;
        string f_Name;
        string f_Pwd;
        while (ifs >> f_Id && ifs >> f_Name && ifs >> f_Pwd)
        {
            if (id == f_Id && name == f_Name && pwd == f_Pwd)
            {
                cout << "Student Login successful" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                studentMenu(person);
                return;
            }
        }
    }
    else if (type == 2)
    {
        int f_Id;
        string f_Name;
        string f_Pwd;
        while (ifs >> f_Id && ifs >> f_Name && ifs >> f_Pwd)
        {
            if (id == f_Id && name == f_Name && pwd == f_Pwd)
            {
                cout << "Teacher Login successful" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                teacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3)
    {
        string f_Name;
        string f_Pwd;
        while (ifs >> f_Name && ifs >> f_Pwd)
        {
            if (name == f_Name && pwd == f_Pwd)
            {
                cout << "Manager Login successful" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
                managerMenu(person);
                return;
            }
        }
    }
    ifs.close();
    cout << "Login failed !!!" << endl;
    system("pause");
    system("cls");
    return;
}

int main()
{
    int choice = 0;
    while (true)
    {
        cout << "Computer room reservation system" << endl;
        cout << "1.Student" << endl;
        cout << "2.Teacher" << endl;
        cout << "3.Manager" << endl;
        cout << "0.Exit" << endl;
        cout << "Please enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1: // Student
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2: // Teacher
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3: // Manager
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0: // Exit
            cout << "Welcome to use it next time" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "Enter Error !!!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}