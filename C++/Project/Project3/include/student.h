#pragma once
#include <iostream>
#include "identity.h"
#include "computerRoom.h"
using namespace std;

class Student : public Identity
{
public:
    int m_ID;
    vector<ComputerRoom> vCom;
public:
    Student();
    Student(int id, string name, string pwd);
    ~Student();
    virtual void openMenu();
    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();
};
