#pragma once
#include <iostream>
#include "identity.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Manager : public Identity
{
public:
<<<<<<< Updated upstream
    vector<Student> vStu;
    vector<Teacher> vTea;
=======
    
>>>>>>> Stashed changes
public:
    Manager();
    Manager(string name, string pwd);
    virtual void openMenu();
    void addPerson();
    void showPerson();
    void showComputer();
    void clearFile();
    void initVector();
<<<<<<< Updated upstream
    bool cheakRepeak(int id,int type);
=======
>>>>>>> Stashed changes
};