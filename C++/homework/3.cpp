#include <iostream>
using namespace std;
class scores
{
public:
    int English[10] = {77, 56, 87, 36, 99, 14, 64, 83, 42, 43};
    void get();
};
void scores::get()
{
    int Add = 0;
    for (int i = 0; i < 10; i++)
        Add += English[i];
    int Average = Add / 10;
    for (int i = 0; i < 10; i++)
    {
        if (English[i] > Average)
            cout << English[i] << endl;
    }
}
int main()
{
    scores s;
    s.get();
    cout << " " << endl;
    system("pause");
    return 0;
}