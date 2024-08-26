#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
/*
选手ABCDE，10个评委分别对每一个选手打分，去除最高分，去除最低分，取平均分
*/
// 选手类
class Person
{
public:
    string m_Name;
    int m_Score;
    Person(string name, int score)
        : m_Name(name), m_Score(score){};
};
void setScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 将评委的分数放入deque容器中
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60; // 40~100随机数
            d.push_back(score);
        }
        // 排序
        sort(d.begin(), d.end());
        // 去除最大值，最小值
        d.pop_back();
        d.pop_front();
        // 求平均数
        int score = 0;
        for (int i = 0; i < d.size(); i++)
        {
            score += d[i];
        }
        int Averagescore;
        Averagescore = score / d.size();
        it->m_Score = Averagescore;
    }
}
void showScore(vector<Person> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].m_Name << " " << v[i].m_Score << endl;
    }
}
int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));
    // 创建5名选手并放入vector容器中
    Person A("A", 0), B("B", 0), C("C", 0), D("D", 0), E("E", 0);
    vector<Person> v;
    v.push_back(A);
    v.push_back(B);
    v.push_back(C);
    v.push_back(D);
    v.push_back(E);
    // 给选手打分
    setScore(v);
    // 显示得分
    showScore(v);
    return 0;
}
