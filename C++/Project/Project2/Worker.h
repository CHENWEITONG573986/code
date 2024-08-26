#pragma once
#include <iostream>
#include <string>
using namespace std;
class Worker // 职工基类
{
public:
    // 显示个人信息
    virtual void Info() = 0;
    // 获得岗位名称
    virtual string DeptName() = 0;
    // 职工编号
    int ID;
    // 职工姓名
    string Name;
    // 部门编号
    int DeptID;
};

class Employee : public Worker // 员工类
{
public:
    Employee(int id, string name, int did);
    // 显示个人信息
    virtual void Info();
    // 获得岗位名称
    virtual string DeptName();
};
Employee::Employee(int id, string name, int did) // 初始化
{
    this->ID = id;
    this->Name = name;
    this->DeptID = did;
}
void Employee::Info() // 显示个人信息
{
    cout << "职工编号：" << this->ID
         << "\t职工姓名：" << this->Name
         << "\t岗位：" << this->DeptName()
         << "\t岗位职责：完成经理交给的任务" << endl;
}
string Employee::DeptName() // 获得岗位名称
{
    return string("员工");
}

class Manager : public Worker // 经理类
{
public:
    Manager(int id, string name, int did);
    // 显示个人信息
    virtual void Info();
    // 获得岗位名称
    virtual string DeptName();
};
Manager::Manager(int id, string name, int did) // 初始化
{
    this->ID = id;
    this->Name = name;
    this->DeptID = did;
}
void Manager::Info() // 显示个人信息
{
    cout << "职工编号：" << this->ID
         << "\t职工姓名：" << this->Name
         << "\t岗位：" << this->DeptName()
         << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}
string Manager::DeptName() // 获得岗位名称
{
    return string("经理");
}

class Boss : public Worker // 老板类
{
public:
    Boss(int id, string name, int did);
    // 显示个人信息
    virtual void Info();
    // 获得岗位名称
    virtual string DeptName();
};
Boss::Boss(int id, string name, int did) // 初始化
{
    this->ID = id;
    this->Name = name;
    this->DeptID = did;
}
void Boss::Info() // 显示个人信息
{
    cout << "职工编号：" << this->ID
         << "\t职工姓名：" << this->Name
         << "\t岗位：" << this->DeptName()
         << "\t岗位职责：管理公司所有事物" << endl;
}
string Boss::DeptName() // 获得岗位名称
{
    return string("老板");
}