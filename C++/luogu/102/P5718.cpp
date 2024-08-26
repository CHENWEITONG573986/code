#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> S;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;
        S.insert(num);
    }
    cout << *S.begin();
}