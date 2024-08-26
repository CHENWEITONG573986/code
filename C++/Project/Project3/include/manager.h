#pragma once
#include <iostream>
#include "identity.h"
using namespace std;

class Manager : public Identity
{
public:
    Manager();
    Manager(string name, string pwd);
    virtual void openMenu();
    void addPerson();
    void showPerson();
    void showComputer();
    void clearFile();
};