#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;
#include "globalFile.h"
#include <fstream>

class OrderFile
{
public:
    int m_Size;
    map<int, map<string, string>> m_orderData;

public:
    OrderFile();
    void updataOrder();
    ~OrderFile(){};
};