#include <iostream>
#include <cmath>
using namespace std;

typedef struct Point
{
    int x;
    int y;
} Point;

class Matrix
{
public:
    Point begin;
    Point end;
    int len = end.x - begin.x + 1;
    static int **matrix;

public:
    Matrix(Point begin, Point end)
        : begin(begin), end(end) {}
};
int **Matrix::matrix = NULL;

void Fun(Matrix M)
{
    if (M.begin.x != M.end.x && M.begin.y != M.end.y)
    {
        for (int i = M.begin.x; i <= M.end.x - (M.len / 2); i++)
        {
            for (int j = M.begin.y; j <= M.end.y - (M.len / 2); j++)
            {
                M.matrix[i][j] = 0;
            }
        }
        Point begin = {M.begin.x + M.len / 2, M.begin.y};
        Point end = {M.end.x, M.end.y - M.len / 2};
        Matrix M1(begin, end);
        Fun(M1);
        begin = {M.begin.x, M.begin.y + M.len / 2};
        end = {M.end.x - M.len / 2, M.end.y};
        Matrix M2(begin, end);
        Fun(M2);
        begin = {M.begin.x + M.len / 2, M.begin.y + M.len / 2};
        end = {M.end.x, M.end.y};
        Matrix M3(begin, end);
        Fun(M3);
    }
}

int main()
{
    int n;
    cin >> n;
    int len = pow(2, n);
    // 开辟动态数组
    int **matrix = new int *[len];
    for (int i = 0; i < len; i++)
        matrix[i] = new int[len];
    // 初始化为1
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            matrix[i][j] = 1;
    Point begin = {0, 0}, end = {len - 1, len - 1};
    Matrix M(begin, end);
    M.matrix = matrix;
    Fun(M);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout << M.matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}