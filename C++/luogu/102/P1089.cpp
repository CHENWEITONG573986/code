#include <iostream>
using namespace std;
int main()
{
    int Budget[12], Money = 0, Deposit[12], sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> Budget[i];
        Money += 300;
        if (Money >= Budget[i])
        {
            Deposit[i] = (Money - Budget[i]) / 100 * 100;
            Money -= Deposit[i];
            sum += Deposit[i];
        }
        else
        {
            cout << "-" << i + 1;
            return 0;
        }
        Money -= Budget[i];
    }
    cout << Money + 1.2 * double(sum);
}