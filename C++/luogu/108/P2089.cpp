#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n > 30)
    {
        cout << "0" << endl;
        return 0;
    }
    vector<vector<int>> V;
    for (int a = 1; a <= 3; a++)
        for (int b = 1; b <= 3; b++)
            for (int c = 1; c <= 3; c++)
                for (int d = 1; d <= 3; d++)
                    for (int e = 1; e <= 3; e++)
                        for (int f = 1; f <= 3; f++)
                            for (int g = 1; g <= 3; g++)
                                for (int h = 1; h <= 3; h++)
                                    for (int i = 1; i <= 3; i++)
                                        for (int j = 1; j <= 3; j++)
                                            if (a + b + c + d + e + f + g + h + i + j == n)
                                            {
                                                vector<int> O;
                                                O.push_back(a);
                                                O.push_back(b);
                                                O.push_back(c);
                                                O.push_back(d);
                                                O.push_back(e);
                                                O.push_back(f);
                                                O.push_back(g);
                                                O.push_back(h);
                                                O.push_back(i);
                                                O.push_back(j);
                                                V.push_back(O);
                                            }
    cout << V.size() << endl;
    for (auto i : V)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}