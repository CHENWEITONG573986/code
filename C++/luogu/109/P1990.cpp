#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> F, G;

int main()
{
    cin >> N;
    F.resize(N + 1);
    G.resize(N + 1);
    F[0] = F[1] = G[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        F[i] = ((F[i - 1] + F[i - 2]) % 10000 + 2 * G[i - 2] % 10000) % 10000;
        G[i] = (G[i - 1] + F[i - 1]) % 10000;
    }
    cout << F[N];
    return 0;
}