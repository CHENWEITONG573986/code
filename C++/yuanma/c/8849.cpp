#include <iostream>
using namespace std;

int RC[81][81], Road[200][200], x = 0, start;

void FindRoad(int temp)
{
    if (temp <= 80)
    {
        for (int j = 1; j < 81; j++)
        {
            if (RC[temp][j] == 1)
            {
                int a = 0;
                for (int i = 0; i < 80; i++)
                {
                    if (Road[start][i] == j)
                        a = 1;
                }
                if (a == 0)
                {
                    Road[start][x] = j;
                    x++;
                }
            }
        }
    }
}

void FindRoadAll(int temp)
{
    if (temp <= 80)
    {
        x = 0;
        int i = 0;
        start = temp - 1;
        FindRoad(temp);
        while (Road[start][i])
        {
            FindRoad(Road[start][i]);
            i++;
        }
    }
}

int main()
{
    for (int i = 0; i < 80; i++)
        for (int j = 0; j < 80; j++)
            Road[i][j] = 0;
    for (int i = 0; i < 81; i++)
        for (int j = 0; j < 81; j++)
            RC[i][j] = 0;
    RC[1][51] = 1, RC[1][75] = 1, RC[2][44] = 1, RC[3][67] = 1, RC[3][65] = 1, RC[4][39] = 1, RC[4][66] = 1, RC[5][49] = 1, RC[5][50] = 1, RC[6][59] = 1, RC[7][32] = 1, RC[7][47] = 1, RC[8][9] = 1, RC[8][47] = 1, RC[9][35] = 1, RC[10][34] = 1;
    RC[11][3] = 1, RC[11][26] = 1, RC[12][25] = 1, RC[14][21] = 1, RC[15][7] = 1, RC[15][31] = 1, RC[16][14] = 1, RC[16][38] = 1, RC[17][40] = 1, RC[17][53] = 1, RC[17][56] = 1, RC[18][67] = 1, RC[18][73] = 1, RC[19][77] = 1, RC[20][66] = 1;
    RC[21][22] = 1, RC[22][4] = 1, RC[23][13] = 1, RC[24][13] = 1, RC[24][25] = 1, RC[25][11] = 1, RC[26][27] = 1, RC[26][10] = 1, RC[27][12] = 1, RC[28][77] = 1, RC[28][15] = 1, RC[29][30] = 1, RC[30][7] = 1, RC[30][48] = 1;
    RC[31][32] = 1, RC[31][34] = 1, RC[32][33] = 1, RC[33][34] = 1, RC[33][8] = 1, RC[34][9] = 1, RC[35][45] = 1, RC[36][35] = 1, RC[36][37] = 1, RC[36][16] = 1, RC[36][80] = 1, RC[37][7] = 1, RC[38][39] = 1, RC[38][41] = 1, RC[39][40] = 1, RC[40][2] = 1;
    RC[41][17] = 1, RC[41][80] = 1, RC[42][43] = 1, RC[43][2] = 1, RC[43][72] = 1, RC[44][3] = 1, RC[45][46] = 1, RC[46][8] = 1, RC[46][55] = 1, RC[47][48] = 1, RC[47][6] = 1, RC[47][5] = 1, RC[48][61] = 1, RC[49][50] = 1, RC[49][53] = 1, RC[50][51] = 1;
    RC[51][52] = 1, RC[51][59] = 1, RC[52][56] = 1, RC[53][52] = 1, RC[53][54] = 1, RC[54][55] = 1, RC[54][63] = 1, RC[55][5] = 1, RC[56][57] = 1, RC[57][58] = 1, RC[57][60] = 1, RC[57][4] = 1, RC[58][59] = 1, RC[60][62] = 1;
    RC[61][60] = 1, RC[62][4] = 1, RC[62][75] = 1, RC[63][64] = 1, RC[64][65] = 1, RC[64][76] = 1, RC[65][66] = 1, RC[66][67] = 1, RC[66][76] = 1, RC[67][44] = 1, RC[67][68] = 1, RC[68][69] = 1, RC[68][75] = 1, RC[69][70] = 1, RC[69][71] = 1, RC[69][8] = 1, RC[70][2] = 1, RC[70][43] = 1,
    RC[71][72] = 1, RC[71][74] = 1, RC[72][73] = 1, RC[73][74] = 1, RC[73][18] = 1, RC[74][1] = 1, RC[74][80] = 1, RC[75][76] = 1, RC[76][77] = 1, RC[77][78] = 1, RC[77][19] = 1, RC[78][79] = 1, RC[79][80] = 1;
    for (int i = 1; i < 81; i++)
        FindRoadAll(i);
    int MIN, temp;
    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 80 - 1; j++)
        {
            for (int k = j + 1; k < 80; k++)
            {
                if (Road[i][j] > Road[i][k])
                {
                    temp = Road[i][j];
                    Road[i][j] = Road[i][k];
                    Road[i][k] = temp;
                }
            }
        }
    }
    for (int i = 0; i < 80; i++)
    {
        cout << i + 1 << "点可通的点：";
        for (int j = 0; j < 80; j++)
        {
            if (Road[i][j] != 0)
                cout << Road[i][j] << " ";
        }
        cout << endl;
    }
}