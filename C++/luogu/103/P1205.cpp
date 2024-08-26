#include <iostream>
using namespace std;
// 开辟方阵
char **MakeMatrix(int n)
{
    // 开辟动态方阵
    char **Matrix = new char *[n];
    // 为每个行分配内存
    for (int i = 0; i < n; i++)
    {
        Matrix[i] = new char[n];
    }
    return Matrix;
}
// 初始化方阵
void init(char **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char a;
            cin >> a;
            A[i][j] = a;
        }
    }
}
// 判断是否相同
bool Same(char **A, char **B, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != B[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
// 顺时针旋转90度
char **Rotate90(char **A, int n)
{
    // 开辟动态方阵
    char **Rotate = MakeMatrix(n);
    // 旋转
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        int k = n - 1;
        for (int j = 0; j < n; j++)
        {
            Rotate[i][j] = A[k][l];
            k--;
        }
        l++;
    }
    return Rotate;
}
// 反射
char **Reflect(char **A, int n)
{
    // 开辟动态方阵
    char **Reflect = MakeMatrix(n);
    // 反射
    for (int i = 0; i < n; i++)
    {
        int k = n - 1;
        for (int j = 0; j < n; j++)
        {
            Reflect[i][j] = A[i][k];
            k--;
        }
    }
    return Reflect;
}
int main()
{
    int n;
    cin >> n;
    // 开辟动态方阵
    char **Matrix1 = MakeMatrix(n);
    char **Matrix2 = MakeMatrix(n);
    // 接收初始方阵和最终方阵
    init(Matrix1, n);
    init(Matrix2, n);
    // 旋转90
    char **Rotate1 = Rotate90(Matrix1, n);
    if (Same(Matrix2, Rotate1, n))
    {
        cout << '1';
        return 0;
    }
    // 旋转180
    char **Rotate2 = Rotate90(Rotate1, n);
    if (Same(Matrix2, Rotate2, n))
    {
        cout << '2';
        return 0;
    }
    // 旋转270
    char **Rotate3 = Rotate90(Rotate2, n);
    if (Same(Matrix2, Rotate3, n))
    {
        cout << '3';
        return 0;
    }
    // 反射
    char **Reflect1 = Reflect(Matrix1, n);
    if (Same(Matrix2, Reflect1, n))
    {
        cout << '4';
        return 0;
    }
    // 反射旋转90度
    char **Reflect2 = Rotate90(Reflect1, n);
    if (Same(Matrix2, Reflect2, n))
    {
        cout << '5';
        return 0;
    }
    // 反射旋转180度
    char **Reflect3 = Rotate90(Reflect2, n);
    if (Same(Matrix2, Reflect3, n))
    {
        cout << '5';
        return 0;
    }
    // 反射旋转270度
    char **Reflect4 = Rotate90(Reflect3, n);
    if (Same(Matrix2, Reflect4, n))
    {
        cout << '5';
        return 0;
    }
    // 不变
    if (Same(Matrix2, Matrix1, n))
    {
        cout << '6';
        return 0;
    }
    // 无效转换
    cout << '7';
    return 0;
}