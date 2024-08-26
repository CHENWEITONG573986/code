#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
class Stite;
class SiteManager;
//**************************************************************************************************
class Site // 网点类
{
protected:
    int ID;             // 站点号
    float X;            // x坐标
    float Y;            // Y坐标
    int Orders;         // 订单量
    int Num;            // 下级网点个数
    int Net[80];        // 下级网点
    friend SiteManager; // 友元声名

public:
    Site(){};
    Site(int ID, float X, float Y, int Orders)
        : ID(ID), X(X), Y(Y), Orders(Orders)
    {
        Num = 0;
        for (int i = 0; i < 80; i++)
            Net[i] = 0;
    };
    // 显示网点信息
    void Show();
};

void Site::Show()
{
    cout << "网点:" << ID << "\t  "
         << "坐标:" << "(" << X << "," << Y << ")" << "   "
         << "订单量:" << Orders << "\t"
         << "下级网点：";
    for (int i = 0; i < 80; i++)
    {
        if (Net[i] != 0)
        {
            cout << Net[i] << " ";
        }
    }
    cout << endl;
}
//**************************************************************************************************
class SiteManager // 网点管理类
{
protected:
    Site **S;         // 管理网点的指针
    int Num;          // 网点数量
    int Road[122][2]; // 线路
    bool File;

public:
    SiteManager();
    // 显示所有网点
    void ShowALLsite();
    // 读取网点数
    void ReadNum();
    // 读取网点信息
    void ReadSite();
    // 读取线路
    void ReadRoad();
    // 找寻网点下级
    void FindNet();
    // 求两点间距离
    float Distance(int A, int B);
    // 寻路
    void Wayfinding();
    ~SiteManager();
};

SiteManager::SiteManager()
{
    this->Num = 0;
    this->S = NULL;
    ReadNum();
    S = new Site *[Num];
    ReadSite();
    ReadRoad();
    FindNet();
}

SiteManager::~SiteManager()
{
    if (S != NULL)
    {
        for (int i = 0; i < Num; i++)
        {
            if (S[i] != NULL)
            {
                delete S[i];
            }
        }
        delete[] S;
    }
}
void SiteManager::ShowALLsite()
{
    for (int i = 0; i < Num; i++)
    {
        S[i]->Show();
    }
}
void SiteManager::ReadNum()
{
    int ID;     // 网点号
    float X;    // x坐标
    float Y;    // Y坐标
    int Orders; // 订单量
    ifstream ifs;
    ifs.open("ccc.txt", ios::in);
    while (ifs >> ID && ifs >> X && ifs >> Y && ifs >> Orders)
    {
        Num++;
    }
    ifs.close();
}
void SiteManager::ReadSite()
{
    int ID;     // 网点号
    float X;    // x坐标
    float Y;    // Y坐标
    int Orders; // 订单量
    int index = 0;
    ifstream ifs;
    ifs.open("ccc.txt", ios::in);
    while (ifs >> ID && ifs >> X && ifs >> Y && ifs >> Orders)
    {
        S[index] = new Site(ID, X, Y, Orders);
        index++;
    }
    ifs.close();
}
void SiteManager::ReadRoad()
{
    ifstream ifs;
    ifs.open("Roed.txt", ios::in);
    for (int i = 0; i < 122; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ifs >> Road[i][j];
        }
    }
    ifs.close();
}
void SiteManager::FindNet()
{
    int SP, EP;
    for (int i = 0; i < 122; i++)
    {
        SP = Road[i][0];
        EP = Road[i][1];
        S[SP - 1]->Net[S[SP - 1]->Num] = EP;
        S[SP - 1]->Num++;
    }
}
float SiteManager::Distance(int A, int B)
{
    float x1, y1, x2, y2, Dis;
    x1 = S[A - 1]->X * 10;
    y1 = S[A - 1]->Y * 10;
    x2 = S[B - 1]->X * 10;
    y2 = S[B - 1]->Y * 10;
    Dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return Dis;
}
void SiteManager::Wayfinding()
{
    for (int i = 0; i < 80; i++)
    {
    }
}
//**************************************************************************************************
int main()
{
    SiteManager SM;
    SM.ShowALLsite();
}