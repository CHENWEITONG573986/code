#include <iostream>
#include <map>
using namespace std;
char matrix[10][10];
bool Bounds(int x, int y)
{
    if (x < 10 && x >= 0 && y < 10 && y >= 0)
        if (matrix[x][y] != '*')
            return true;
    return false;
}

class Player
{
public:
    int x;
    int y;
    int move = 0;
    char name;

public:
    void Move()
    {
        // 上
        if (move == 0)
        {
            if (Bounds(x - 1, y))
            {
                matrix[x][y] = '.';
                x--;
                matrix[x][y] = name;
            }
            else
            {
                move++;
                move %= 4;
            }
        }
        // 右
        else if (move == 1)
        {
            if (Bounds(x, y + 1))
            {
                matrix[x][y] = '.';
                y++;
                matrix[x][y] = name;
            }
            else
            {
                move++;
                move %= 4;
            }
        }
        // 下
        else if (move == 2)
        {
            if (Bounds(x + 1, y))
            {
                matrix[x][y] = '.';
                x++;
                matrix[x][y] = name;
            }
            else
            {
                move++;
                move %= 4;
            }
        }
        // 左
        else if (move == 3)
        {
            if (Bounds(x, y - 1))
            {
                matrix[x][y] = '.';
                y--;
                matrix[x][y] = name;
            }
            else
            {
                move++;
                move %= 4;
            }
        }
    }
};

bool Win(Player &A, Player &B)
{
    if (A.x == B.x && A.y == B.y)
        return false;
    return true;
}

int main()
{
    Player F, C, OF, OC;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'F')
            {
                F.x = i;
                F.y = j;
                F.name = 'F';
                OF = F;
            }
            if (matrix[i][j] == 'C')
            {
                C.x = i;
                C.y = j;
                C.name = 'C';
                OC = C;
            }
        }
    int count = 0;
    int tdz;
    map<int, int> M;
    while (Win(F, C))
    {
        tdz = F.x + F.y * 10 + C.x * 100 + C.y * 1000 + F.move * 10000 + C.move * 40000;
        C.Move();
        F.Move();
        if (M[tdz])
        {
            cout << "0" << endl;
            return 0;
        }
        M[tdz] = 1;
        count++;
    }
    cout << count;
    return 0;
}