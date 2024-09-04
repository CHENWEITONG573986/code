#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> V;

int main()
{
    cin >> n;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int count = V[0];
    for (int i = 1; i < n; i++)
        if (V[i] > V[i - 1])
            count += V[i] - V[i - 1];
    cout << count;
    return 0;
}

// int main()
// {
//     cin >> n;
//     V.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> V[i];
//     int count = 0;
//     bool t = true;
//     while (t)
//     {
//         t = false;
//         for (int i = 0; i < n; i++)
//         {
//             if (V[i] == 0 && t)
//                 break;
//             if (V[i] > 0)
//             {
//                 V[i]--;
//                 t = true;
//             }
//         }
//         count++;
//     }
//     cout << --count;
//     return 0;
// }