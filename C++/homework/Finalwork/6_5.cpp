#include <iostream>
using namespace std;
template <class T1, class T2>
class Compare
{
private:
    T1 A;
    T2 B;

public:
    Compare(){};
    Compare(T1 A, T2 B) : A(A), B(B){};
    void FindMax();
    ~Compare(){};
};
template <class T1, class T2>
void Compare<T1,T2>::FindMax()
{
    if (A > B)
    {
        cout << A << endl;
    }
    else
    {
        cout << B << endl;
    }
}
int main()
{
    int A = 10;
    float B = 10.1;
    Compare<int, float> C(A, B);
    C.FindMax();
    system("pause");
    return 0;
}