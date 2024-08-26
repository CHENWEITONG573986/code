#include <iostream>
using namespace std;
class str
{
public:
    int a[7]={3,7,8,9,10,4,5};
    void getevenadd();
};
void str::getevenadd()
{
    int add=0;
    for(int i=0;i<7;i++)
    {
        if(a[i]%2==0)
        {
            add+=a[i];
        }
    }
    cout << add << endl;
}
int main()
{
    str s;
    s.getevenadd();
    system("pause");
    return 0;
}