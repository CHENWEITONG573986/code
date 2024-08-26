#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, Win[7], Num[7], Prize[7] = {0, 0, 0, 0, 0, 0, 0};
    cin >> n;
    for (int i = 0; i < 7; i++)
    {
        cin >> Win[i];
    }
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < 7; j++)
        {
            cin >> Num[j];
            for (int k = 0; k < 7; k++)
            {
                if (Win[k] == Num[j])
                {
                    num++;
                }
            }
        }
        switch (num)
        {
        case 1:
            Prize[6]++;
            break;
        case 2:
            Prize[5]++;
            break;
        case 3:
            Prize[4]++;
            break;
        case 4:
            Prize[3]++;
            break;
        case 5:
            Prize[2]++;
            break;
        case 6:
            Prize[1]++;
            break;
        case 7:
            Prize[0]++;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << Prize[i] << " ";
    }
}