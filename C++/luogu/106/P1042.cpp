#include <iostream>
#include <string>
using namespace std;

class Contest
{
public:
    int win = 0;
    int low = 0;
    int format;

public:
    Contest(int format) : format(format) {}
    void push(char results)
    {
        if (results == 'W')
            this->win++;
        else if (results == 'L')
            this->low++;
        else if (results == 'E')
            print();
    }
    void summarize()
    {
        if ((win - low <= -2 || win - low >= 2) && (win >= format || low >= format))
        {
            this->print();
            win = 0;
            low = 0;
        }
    }
    void print()
    {
        cout << win << ':' << low << endl;
    }
};

int main()
{
    string str;
    while (true)
    {
        char results;
        cin >> results;
        str.push_back(results);
        if (results == 'E')
            break;
    }
    Contest C11(11);
    for (char c : str)
    {
        C11.push(c);
        C11.summarize();
    }
    cout << endl;
    Contest C21(21);
    for (char c : str)
    {
        C21.push(c);
        C21.summarize();
    }
    return 0;
}