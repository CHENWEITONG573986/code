#include "teacher.h"

Teacher::Teacher()
{
}
Teacher::Teacher(int empId, string name, string pwd)
{
    this->m_empId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}
Teacher::~Teacher()
{
}
void Teacher::openMenu()
{
    cout << "Teacher: " << this->m_Name << "Login" << endl;
    cout << "1.showAllOrder" << endl;
    cout << "2.vaildOrder" << endl;
    cout << "0.Sign out" << endl;
    cout << "Please Enter your select:";
}
void Teacher::showAllOrder()
{
    OrderFile of;
    if (!of.m_Size)
    {
        cout << "No records!!!" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < of.m_Size; i++)
    {
        cout << "Data:";
        switch (stoi(of.m_orderData[i]["Data"]))
        {
        case 1:
            cout << "Monday" << " ";
            break;
        case 2:
            cout << "Tuesday" << " ";
            break;
        case 3:
            cout << "Wednesday" << " ";
            break;
        case 4:
            cout << "Thursday" << " ";
            break;
        case 5:
            cout << "Friday" << " ";
        }
        cout << "Interval:";
        switch (stoi(of.m_orderData[i]["Interval"]))
        {
        case 1:
            cout << "morning" << " ";
            break;
        case 2:
            cout << "Afternoon" << " ";
            break;
        }
        cout << "Id:" << stoi(of.m_orderData[i]["Id"]) << " ";
        cout << "Name:" << stoi(of.m_orderData[i]["Name"]) << " ";
        cout << "Room:" << stoi(of.m_orderData[i]["Room"]) << " ";
        cout << "Status:";
        switch (stoi(of.m_orderData[i]["Status"]))
        {
        case 1:
            cout << "Under review" << endl;
            break;
        case 2:
            cout << "succeed" << endl;
            break;
        case 3:
            cout << "fail" << endl;
            break;
        case 0:
            cout << "Cancel" << endl;
            break;
        }
    }
    system("pause");
    system("cls");
}
void Teacher::vaildOrder()
{
    OrderFile of;
    if (!of.m_Size)
    {
        cout << "No records!!!" << endl;
        system("pause");
        system("cls");
        return;
    }
    vector<int> V;
    int index = 0;
    for (int i = 0; i < of.m_Size; i++)
    {
        if (of.m_orderData[i]["Status"] == "1")
        {
            V.push_back(i);
            cout << ++index << " ";
            cout << "Data:";
            switch (stoi(of.m_orderData[i]["Data"]))
            {
            case 1:
                cout << "Monday" << " ";
                break;
            case 2:
                cout << "Tuesday" << " ";
                break;
            case 3:
                cout << "Wednesday" << " ";
                break;
            case 4:
                cout << "Thursday" << " ";
                break;
            case 5:
                cout << "Friday" << " ";
            }
            cout << "Interval:";
            switch (stoi(of.m_orderData[i]["Interval"]))
            {
            case 1:
                cout << "morning" << " ";
                break;
            case 2:
                cout << "Afternoon" << " ";
                break;
            }
            cout << "Id:" << stoi(of.m_orderData[i]["Id"]) << " ";
            cout << "Name:" << stoi(of.m_orderData[i]["Name"]) << " ";
            cout << "Room:" << stoi(of.m_orderData[i]["Room"]) << endl;
        }
    }
    cout << "Enter your select (0-back):";
    int select = 0;
    int ret = 0;
    while (true)
    {
        cin >> select;
        if (select >= 0 && select <= V.size())
        {
            if (!select)
                break;
            else
            {
                cout << "Please Enter your select:" << endl;
                cout << "1.Pass" << endl;
                cout << "2.Not Pass" << endl;
                cin >> ret;
                if (ret == 1)
                {
                    of.m_orderData[V[select - 1]]["Status"] = '2';
                }
                else
                {
                    of.m_orderData[V[select - 1]]["Status"] = '3';
                }
                of.updataOrder();
                cout << "The review is complete" << endl;
                break;
            }
        }
        cout << "Enter Error!!!" << endl;
    }
    system("pause");
    system("cls");
}