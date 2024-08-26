#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager // 员工管理类
{
public:
    WorkerManager();
    void menu();         // 菜单
    void Exit();         // 退出
    void Save();         // 保存
    void InitEmp();      // 初始化员工
    void AddEmp();       // 添加
    void ShowEmp();      // 显示
    void DelEmp();       // 删除
    void ModEmp();       // 修改
    void FindEmp();      // 查找
    void SortEmp();      // 排序
    void CleanFile();    // 清空
    int IsExist(int id); // 判断职工是否存在,并返回他在文件中的位置
    int GetEmpNum();     // 读取人数
    ~WorkerManager();
    int EmpNum;        // 记录人数
    Worker **EmpArray; // 职工数组指针
    bool File;         // 判断文件是否为空
};

int WorkerManager::GetEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }
    return num;
}

void WorkerManager::InitEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if (did == 1)
        {
            worker = new Employee(id, name, did);
        }
        if (did == 2)
        {
            worker = new Manager(id, name, did);
        }
        if (did == 3)
        {
            worker = new Boss(id, name, did);
        }
        this->EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

WorkerManager::WorkerManager()
{
    // 初始化
    this->EmpNum = 0;
    this->EmpArray = NULL;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->File = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        this->File = true;
        ifs.close();
        return;
    }
    this->File = false; // 文件不为空
    this->EmpNum = this->GetEmpNum();
    cout << "职工人数为：" << this->EmpNum << endl;
    // 开辟空间
    this->EmpArray = new Worker *[this->EmpNum];
    // 存放数据
    this->InitEmp();
}

WorkerManager::~WorkerManager()
{
    // 释放堆区空间
    if (this->EmpArray != NULL)
    {
        for (int i = 0; i < this->EmpNum; i++)
        {
            if (this->EmpArray[i] != NULL)
            {
                delete this->EmpArray[i];
            }
        }
        delete[] this->EmpArray;
        this->EmpArray = NULL;
    }
}

void WorkerManager::menu()
{
    cout << "**********************************************" << endl;
    cout << "**                                          **" << endl;
    cout << "**              欢迎使用本系统              **" << endl;
    cout << "**                                          **" << endl;
    cout << "**********************************************" << endl;
    cout << "**-----------------功能菜单-----------------**" << endl;
    cout << "**          添加职工 ------------1          **" << endl;
    cout << "**          显示职工 ------------2          **" << endl;
    cout << "**          删除职工 ------------3          **" << endl;
    cout << "**          修改职工 ------------4          **" << endl;
    cout << "**          查找职工 ------------5          **" << endl;
    cout << "**          排序职工 ------------6          **" << endl;
    cout << "**          清空数据 ------------7          **" << endl;
    cout << "**          退出系统 ------------0          **" << endl;
    cout << "**********************************************\n"
         << endl;
}

void WorkerManager::Exit()
{
    cout << "**********************************************" << endl;
    cout << "**                                          **" << endl;
    cout << "**        欢迎下次使用！~再见！~~           **" << endl;
    cout << "**                                          **" << endl;
    cout << "**********************************************" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::Save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 用输出方式打开文件--写文件
    for (int i = 0; i < this->EmpNum; i++)
    {
        ofs << this->EmpArray[i]->ID << " "
            << this->EmpArray[i]->Name << " "
            << this->EmpArray[i]->DeptID << endl;
    }
    ofs.close();
}

void WorkerManager::AddEmp()
{
    cout << "请输入添加职工数量：" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0)
    {
        // 计算添加之后的空间大小
        int newSize = this->EmpNum + addNum; // 新人数=原始人数+新增人数
        // 开辟新的空间
        Worker **newSpace = new Worker *[newSize];
        // 将原有的数据拷贝到新空间下
        if (this->EmpArray != NULL)
        {
            for (int i = 0; i < this->EmpNum; i++)
            {
                newSpace[i] = this->EmpArray[i];
            }
        }
        // 添加新的数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;
            cout << "请输入第" << i + 1 << "个职工的编号:" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个职工的姓名:" << endl;
            cin >> name;
            cout << "请选择该职工的工作岗位：" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            // 保存到数组
            newSpace[this->EmpNum + i] = worker;
        }
        // 释放原有空间
        delete[] this->EmpArray;
        // 更新空间指向
        this->EmpArray = newSpace;
        // 更新人数
        this->EmpNum = newSize;
        // 保存数据到文件
        this->Save();
        // 更改文件不为空
        this->File = false;
        // 提示
        cout << "成功添加" << addNum << "名新职工" << endl;
    }
    else
    {
        cout << "输入数据有误" << endl;
    }
    // system("pause");
    // system("cls");
}

void WorkerManager::ShowEmp()
{
    if (this->File)
    {
        cout << "文件不存在或者记录为空！" << endl;
    }
    else
    {
        cout << "共有职工" << this->EmpNum << "人，数据如下：" << endl;
        for (int i = 0; i < this->EmpNum; i++)
        {
            this->EmpArray[i]->Info();
        }
    }
    // system("pause");
    // system("cls");
}

void WorkerManager::DelEmp() // 删除
{
    if (this->File)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入想要删除的职工编号：" << endl;
        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1)
        {
            cout << "查询如下：" << endl;
            this->EmpArray[index]->Info();
            cout << "确认是否删除此职工数据(是1,否0):";
            int a;
            cin >> a;
            if (a)
            {
                for (int i = index; i < this->EmpNum - 1; i++)
                {
                    // 数据前移
                    this->EmpArray[i] = this->EmpArray[i + 1];
                }
                // 更新人数
                this->EmpNum--;
                // 同步数据到文件
                this->Save();
                cout << "删除成功！" << endl;
            }
        }
        else
        {
            cout << "删除失败，查无此人" << endl;
        }
    }
    // system("pause");
    // system("cls");
}
// 判断职工是否存在
int WorkerManager::IsExist(int id)
{
    for (int i = 0; i < this->EmpNum; i++)
    {
        if (this->EmpArray[i]->ID == id)
        {
            return i;
        }
    }
    return -1;
}

void WorkerManager::ModEmp()
{
    if (this->File)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1)
        {
            cout << "查询如下：" << endl;
            this->EmpArray[ret]->Info();
            cout << "确认是否修改此职工数据(是1,否0):";
            delete this->EmpArray[ret];
            int newid = 0;
            string newname;
            int newdid = 0;
            int a;
            cin >> a;
            if (a)
            {
                cout << "请输入新的职工号：" << endl;
                cin >> newid;
                cout << "请输入新的姓名：" << endl;
                cin >> newname;
                cout << "请选择该职工的工作岗位：" << endl;
                cout << "1.员工" << endl;
                cout << "2.经理" << endl;
                cout << "3.老板" << endl;
                cin >> newdid;
                Worker *worker = NULL;
                switch (newdid)
                {
                case 1:
                    worker = new Employee(newid, newname, newdid);
                    break;
                case 2:
                    worker = new Manager(newid, newname, newdid);
                    break;
                case 3:
                    worker = new Boss(newid, newname, newdid);
                    break;
                }
                this->EmpArray[ret] = worker;
                this->Save();
                cout << "修改成功" << endl;
            }
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }
    // system("pause");
    // system("cls");
}

void WorkerManager::FindEmp()
{
    if (this->File)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请选择查找方式" << endl;
        cout << "1.编号查找" << endl;
        cout << "2.姓名查找" << endl;
        int a;
        cin >> a;
        if (a == 1)
        {
            cout << "请输入查找编号：" << endl;
            int id;
            cin >> id;
            int index = this->IsExist(id);
            if (index != -1)
            {
                cout << "查找到的数据如下：" << endl;
                this->EmpArray[index]->Info();
            }
            else
            {
                cout << "***查无此人***" << endl;
            }
        }
        else if (a == 2)
        {
            string name;
            cout << "请输入查找姓名：" << endl;
            cin >> name;
            bool flag = true;
            for (int i = 0; i < this->EmpNum; i++)
            {
                if (this->EmpArray[i]->Name == name)
                {
                    cout << "查找到的数据如下：" << endl;
                    this->EmpArray[i]->Info();
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "***查无此人***" << endl;
            }
        }
    }
    // system("pause");
    // system("cls");
}

void WorkerManager::SortEmp()
{
    if (this->File)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        cout << "请选择排序方式：" << endl;
        cout << "1.职工号升序" << endl;
        cout << "2.职工号降序" << endl;
        int a = 0;
        cin >> a;
        for (int i = 0; i < this->EmpNum - 1; i++)
        {
            int MinOrMax = i;
            for (int j = i + 1; j < this->EmpNum; j++)
            {
                if (a == 1)
                {
                    if (this->EmpArray[MinOrMax]->ID > this->EmpArray[j]->ID)
                    {
                        MinOrMax = j;
                    }
                }
                else if (a == 2)
                {
                    if (this->EmpArray[MinOrMax]->ID < this->EmpArray[j]->ID)
                    {
                        MinOrMax = j;
                    }
                }
                else
                {
                    cout << "***输入有误***" << endl;
                }
                if (i != MinOrMax)
                {
                    Worker *temp = NULL;
                    temp = this->EmpArray[i];
                    this->EmpArray[i] = this->EmpArray[MinOrMax];
                    this->EmpArray[MinOrMax] = temp;
                }
            }
        }
        this->Save();
        cout << "排序成功,排序后的结果为：" << endl;
        this->ShowEmp();
    }
}
void WorkerManager::CleanFile()
{
    cout << "确定清空所有数据？" << endl;
    cout << "1.确定" << endl;
    cout << "2.返回" << endl;
    int a = 0;
    cin >> a;
    if (a == 1)
    {
        ofstream ofs;
        ofs.open(FILENAME, ios::trunc); // trunc发开方式，删除文件后创建
        ofs.close();
        if (this->EmpArray != NULL)
        {
            for (int i = 0; i < this->EmpNum; i++)
            {
                if (this->EmpArray[i] != NULL)
                {
                    delete this->EmpArray[i];
                    this->EmpArray[i] = NULL;
                }
            }
            delete this->EmpArray;
            // 重置属性值
            this->EmpArray = NULL;
            this->EmpNum = 0;
            this->File = true;
        }
        cout<<"***清空成功***"<<endl;
    }
    // system("pause");
    // system("cls");
}