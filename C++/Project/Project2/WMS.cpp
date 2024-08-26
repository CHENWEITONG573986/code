#include <iostream>
#include <string>
#include "Worker.h"        //职工类
#include "WorkerManager.h" //职工管理类
using namespace std;

int main()
{
    WorkerManager WM;
    int choice = 0;
    while (true)
    {
        WM.menu();
        cout << "亲输入您的选择:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出系统
            WM.Exit();
            break;
        case 1: // 添加职工
            WM.AddEmp();
            break;
        case 2: // 显示职工
            WM.ShowEmp();
            break;
        case 3: // 删除职工
            WM.DelEmp();
            break;
        case 4: // 修改职工
            WM.ModEmp();
            break;
        case 5: // 查找职工
            WM.FindEmp();
            break;
        case 6: // 职工排序
            WM.SortEmp();
        case 7: // 清空职工
            WM.CleanFile();
            break;
        default:
            // system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}