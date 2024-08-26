#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
using namespace std;
class Worker
{
public:
    string m_Name;
    int m_Salary;
    Worker(){};
    Worker(string name)
    {
        this->m_Name = name;
        this->m_Salary = rand() % 6001 + 6000;
    }
};

void printVector(const vector<Worker> &V)
{
    for (vector<Worker>::const_iterator it = V.begin(); it != V.end(); it++)
    {
        cout << "姓名：" << it->m_Name << "\t工资：" << it->m_Salary << endl;
    }
}

void printMultimap(const multimap<int, Worker> &M)
{
    for (multimap<int, Worker>::const_iterator it = M.begin(); it != M.end(); it++)
    {
        switch (it->first)
        {
        case 0:
            cout << "部门：策划部" << "\t姓名：" << it->second.m_Name << "\t工资：" << it->second.m_Salary << endl;
            break;
        case 1:
            cout << "部门：美术部" << "\t姓名：" << it->second.m_Name << "\t工资：" << it->second.m_Salary << endl;
            break;
        case 2:
            cout << "部门：研发部" << "\t姓名：" << it->second.m_Name << "\t工资：" << it->second.m_Salary << endl;
            break;
        }
    }
}

void setVector(vector<Worker> &V)
{
    for (char name = 'A'; name < 'K'; name++)
    {
        string Name = "员工";
        Name += name;
        V.push_back(Worker(Name));
    }
}

void setMultiMap(multimap<int, Worker> &M, vector<Worker> &V)
{
    for (vector<Worker>::const_iterator it = V.begin(); it != V.end(); it++)
    {
        int id = rand() % 3;
        M.insert(pair<int, Worker>(id, *it));
    }
}

void showDepartment(multimap<int, Worker> &M)
{
    cout << "策划部：" << endl;
    for (multimap<int, Worker>::const_iterator it = M.begin(); it != M.end(); it++)
    {
        if (it->first == 0)
        {
            cout << "姓名：" << it->second.m_Name << "\t工资：" << it->second.m_Salary << endl;
        }
    }
    cout << endl;
    cout << "美术部：" << endl;
    for (multimap<int, Worker>::const_iterator it = M.begin(); it != M.end(); it++)
    {
        if (it->first == 1)
        {
            cout << "姓名：" << it->second.m_Name << "\t工资：" << it->second.m_Salary << endl;
        }
    }
    cout << endl;
    cout << "研发部：" << endl;
    for (multimap<int, Worker>::const_iterator it = M.begin(); it != M.end(); it++)
    {
        if (it->first == 2)
        {
            cout << "姓名：" << it->second.m_Name << "\t工资：" << it->second.m_Salary << endl;
        }
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    vector<Worker> V;
    setVector(V);
    printVector(V);
    multimap<int, Worker> M;
    setMultiMap(M, V);
    printMultimap(M);
    showDepartment(M);
    return 0;
}