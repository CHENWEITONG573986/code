#pragma once
#include <iostream>
#include <string>
using namespace std;
// ѡ����
class Speaker
{
public:
    // ѡ������
    string m_Name;
    // ѡ�ַ���
    double m_Sorce[2];

public:
    Speaker();
    Speaker(string name);
    ~Speaker();
};
