#include <iostream>
using namespace std;

struct ST
{
    int a;
};

class CL
{
    int a;
};

int main()
{
    // sturct与calss的区别
    // sturct 默认公共权限
    // calss 默认私有权限
    ST st;
    st.a = 1;

    CL cl;
    // cl.a=1;
    return 0;
}