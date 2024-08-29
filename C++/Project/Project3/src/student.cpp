#include "Student.h"

Student::Student()
{
}
Student::Student(int id, string name, string pwd)
{
    this->m_ID = id;
    this->m_Name = name;
    this->m_Pwd = pwd;
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
    {
        vCom.push_back(com);
    }
    ifs.close();
}
Student::~Student()
{
}
void Student::openMenu()
{
    cout << "Student: " << this->m_Name << " Login" << endl;
    cout << "1.applyOrder" << endl;
    cout << "2.showMyOrder" << endl;
    cout << "3.showAllOrder" << endl;
    cout << "4.cancelOrder" << endl;
    cout << "0.Sign out" << endl;
    cout << "Please Enter your select:";
}
void printRoom(ComputerRoom &c)
{
    cout << "ID:" << c.m_ComId << " MaxNum:" << c.m_MaxNum << endl;
}
void Student::applyOrder()
{
    int data = 0;
    int interval = 0;
    int room = 0;
    cout << "Please select a date" << endl;
    cout << "1.Monday" << endl;
    cout << "2.Tuesday" << endl;
    cout << "3.Wednesday" << endl;
    cout << "4.Thursday" << endl;
    cout << "5.Friday" << endl;
    while (true)
    {
        cin >> data;
        if (data >= 1 && data <= 5)
            break;
        cout << "Data Error!!!" << endl;
    }
    cout << "Please select a interval" << endl;
    cout << "1.morning" << endl;
    cout << "2.Afternoon" << endl;
    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
            break;
        cout << "Interval Error!!!" << endl;
    }
    cout << "Please select a room" << endl;
    for_each(vCom.begin(), vCom.end(), printRoom);
    while (true)
    {
        cin >> room;
        int a = 0;
        for (int i = 0; i < vCom.size(); i++)
            if (vCom[i].m_ComId == room)
            {
                a = 1;
                break;
            }
        if (a)
            break;
        cout << "room Error!!!" << endl;
    }
    cout << "Order succeed Under review" << endl;
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "Data:" << data << " ";
    ofs << "Interval:" << interval << " ";
    ofs << "Id:" << m_ID << " ";
    ofs << "Name:" << m_Name << " ";
    ofs << "Room:" << room << " ";
    ofs << "Status:" << 1 << endl;
    ofs.close();
    system("pause");
    system("cls");
}
void Student::showMyOrder()
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
        if (stoi(of.m_orderData[i]["Id"]) == m_ID)
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
    }
    system("pause");
    system("cls");
}
void Student::showAllOrder()
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
void Student::cancelOrder()
{
    OrderFile of;
    if (!of.m_Size)
    {
        cout << "No records!!!" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "Please Enter num:" << endl;
    int index = 1;
    vector<int> V;
    for (int i = 0; i < of.m_Size; i++)
    {
        if (m_ID == stoi(of.m_orderData[i]["Id"]))
        {
            if (of.m_orderData[i]["Status"] == "1" || of.m_orderData[i]["Status"] == "2")
            {
                V.push_back(i);
                cout << index++ << " ";
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
        }
    }
    int select = 0;
    while (true)
    {
        cin >> select;
        if (select >= 0 && select <= V.size())
        {
            if (select == 0)
                break;
            else
            {
                of.m_orderData[V[select - 1]]["Status"] = "0";
                of.updataOrder();
                cout << "The cancellation was successful" << endl;
                break;
            }
        }
        cout << "Enter Error!!!" << endl;
    }
    system("pause");
    system("cls");
}