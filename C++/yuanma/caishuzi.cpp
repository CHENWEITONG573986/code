#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    srand((unsigned int)time(NULL)); //随机种子，防止每次随机数字相同。
    int num,a,i=0,b=1;
    num=rand()%100+1;  //生成1~100的随机数
    cout << "《猜数字游戏》" << endl;
    cout << "猜测范围1~100,您有5次机会" << endl;
    while(i<5)
    {
        cout << "请输入您猜测的数字：";
        cin >> a;
        if(a>num)
            cout << "猜测过大" << endl;
        else if(a<num)
            cout << "猜测过小" << endl;
        else
        {
            cout << "恭喜您猜对了" << endl;
            b=0;
            break;
        }
        i++;
        if(i<5)cout << "您还有" << 5-i << "次机会" << endl;
    }
    if(b) cout << "游戏失败" << endl;
    system("pause");
    return 0;
}