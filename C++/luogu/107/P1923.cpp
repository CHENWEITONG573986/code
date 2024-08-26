#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> V;
    V.resize(n);   
    for (int i = 0; i < n; i++)
        scanf("%d", &V[i]);
    sort(V.begin(), V.end()); // 快排
    printf("%d", V[k]);
    return 0;
}