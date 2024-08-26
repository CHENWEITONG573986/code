#pragma once
#include <iostream>
#include <string>
using namespace std;
// 选手类
class Speaker
{
public:
    // 选手姓名
    string m_Name;
    // 选手分数
    double m_Sorce[2];

public:
    Speaker();
    Speaker(string name);
    ~Speaker();
};
