#pragma once
#include <iostream>
#include <identity.h>
using namespace std;

class Teacher : public Identity
{
public:
    int m_empId;

public:
    Teacher();
    Teacher(int empId, string name, string pwd);
    ~Teacher();
    virtual void openMenu();
    void showAllOrder();
    void vaildOrder();
};