#include <iostream>
#include <string>
using namespace std;
class Account
{
protected:
    int accunmber;
    string name;

public:
    Account(){};
    Account(int accunmber, string name)
        : accunmber(accunmber), name(name){};
    void show();
    ~Account(){};
};
class CreditAccount : public Account
{
private:
    int credit;

public:
    CreditAccount(){};
    CreditAccount(int accunmber, string name, int credit)
        : Account(accunmber, name), credit(credit){};
    void show();
    ~CreditAccount(){};
};
void Account::show()
{
    cout << "账号：" << accunmber << endl;
    cout << "姓名：" << name << endl;
}

void CreditAccount::show()
{
    Account::show();
    cout << "信用额度：" << credit << endl;
}

int main()
{
    CreditAccount C(123456, "吴彦祖", 100);
    C.show();
    system("pause");
    return 0;
}