#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
float Site[80][4], Roed[122][2], TD[80];
int RC[80][80], Net[80][80], x, start;
// 读取网点数据
void Read()
{
    ifstream ifs1;
    ifs1.open("ccc.txt", ios::in);
    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ifs1 >> Site[i][j];
        }
    }
    ifs1.close();
    ifstream ifs2;
    ifs2.open("Roed.txt", ios::in);
    for (int i = 0; i < 122; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ifs2 >> Roed[i][j];
        }
    }
    ifs2.close();
}
// 求两点距离
float Distance(int A, int B)
{
    float x1, y1, x2, y2, Dis;
    x1 = Site[A - 1][1] * 10;
    y1 = Site[A - 1][2] * 10;
    x2 = Site[B - 1][1] * 10;
    y2 = Site[B - 1][2] * 10;
    Dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return Dis;
}
// 转化通路矩阵
void RoedToRC()
{
    int a, b;
    for (int i = 0; i < 122; i++)
    {
        a = Roed[i][0];
        b = Roed[i][1];
        RC[a - 1][b - 1] = 1;
    }
}
// 找该点可去往的下一级点
void FindRoad(int temp) // temp为该点减一
{
    for (int j = 0; j < 80; j++)
    {
        if (RC[temp][j] == 1)
        {
            int a = 0;
            for (int i = 0; i < 80; i++)
            {
                if (Net[start][i] == j + 1)
                    a = 1;
            }
            if (a == 0)
            {
                Net[start][x] = j + 1;
                x++;
                TD[start] += Distance(temp + 1, j + 1);
            }
        }
    }
}
// 找80点各点可去往的全部的点
void FindRoadAll()
{
    for (int i = 0; i < 80; i++)
    {
        x = 0;
        int a = 0;
        start = i;
        FindRoad(i);
        while (Net[start][a])
        {
            FindRoad(Net[start][a] - 1);
            a++;
        }
    }
}
// 给通路排序
void SelectSort()
{
    int temp;
    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 80 - 1; j++)
        {
            for (int k = j + 1; k < 80; k++)
            {
                if (Net[i][j] > Net[i][k])
                {
                    temp = Net[i][j];
                    Net[i][j] = Net[i][k];
                    Net[i][k] = temp;
                }
            }
        }
    }
}
// 输出通路网
void putNet()
{
    for (int i = 0; i < 80; i++)
    {
        cout << i + 1 << "点可通的点：";
        for (int j = 0; j < 80; j++)
        {
            if (Net[i][j] != 0)
                cout << Net[i][j] << " ";
        }
        cout << endl;
    }
}
// 输出总路程
void putTD()
{
    for (int i = 0; i < 80; i++)
    {
        cout << i + 1 << "点总路程：" << TD[i] << endl;
    }
}
int main()
{
    Read();
    RoedToRC();
    FindRoadAll();
    SelectSort();
    putNet();
    putTD();
}