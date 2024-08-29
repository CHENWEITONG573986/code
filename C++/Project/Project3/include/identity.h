#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

// Identity-based classes
class Identity
{
public:
    // Action menu
    virtual void openMenu() = 0; 
    string m_Name;
    string m_Pwd;
};