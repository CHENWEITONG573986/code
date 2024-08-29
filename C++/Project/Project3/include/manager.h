#pragma once
#include <iostream>
#include "identity.h"
#include "computerRoom.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Manager : public Identity
{
public:
    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<ComputerRoom> vCom;
public:
    Manager();
    Manager(string name, string pwd);
    virtual void openMenu();
    void addPerson();
    void showPerson();
    void showComputer();
    void clearFile();
    void initVector();
    bool cheakRepeak(int id,int type);
};