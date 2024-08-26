#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, m;
    int a = 0;
    cin >> n >> m;
    char O[5] = {'0', '2', '4', '6', '8'}, J[5] = {'1', '3', '5', '7', '9'};
    char Z[100];
    for (int i = 0; i < n; i++)
    {
        if ((n - i) % 2 == 0)
        {
            if (i == 0)
            {
                Z[i] = O[1];
            }
            else
            {
                Z[i] = O[0];
            }
        }
        else
        {
            Z[i] = J[0];
        }
    }
    cout << Z << endl;
    int q,w,e,r,t;
    for(int i=n;i>=0;i--)
    {
        if ((n-i+1) % 2 == 0)
        {
            for(int j=1;j<5;j++)
            {
                for(int k=0;k<n-4;k++)
                {
                    q=Z[k]-'0';
                    w=Z[k+1]-'0';
                    e=Z[k+2]-'0';
                    r=Z[k+3]-'0';
                    t=Z[k+4]-'0';
                    if(q+w+e+r+t<m)
                    {
                        cout << Z << endl;
                    }
                }
                Z[i]=O[j];
            }
        }
        else
        {
            for(int j=1;j<5;j++)
            {
                for(int k=0;k<n-4;k++)
                {
                    q=Z[k]-'0';
                    w=Z[k+1]-'0';
                    e=Z[k+2]-'0';
                    r=Z[k+3]-'0';
                    t=Z[k+4]-'0';
                    if(q+w+e+r+t<m)
                    {
                        cout << Z << endl;
                    }
                }
                Z[i]=J[j];
            }
        }
    }
    system("pause");
    return 0;
}
