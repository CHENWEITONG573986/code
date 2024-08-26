#include <iostream>
#include <string>
using namespace std;
//**************************************
class Account
{
protected:
    int accnumber;
    string accname;

public:
    Account(){};
    Account(int num, string name);
    void Show();
};
//**************************************
class CreditAccount : public Account
{
private:
    int credit;

public:
    CreditAccount(){};
    CreditAccount(int num, string name, int credit);
    void Show();
};
//**************************************
Account::Account(int num, string name)
{
    this->accnumber = num;
    this->accname = name;
}
void Account::Show()
{
    cout << "编号为：" << this->accnumber << endl;
    cout << "姓名为：" << this->accname << endl;
}
//**************************************
CreditAccount::CreditAccount(int num, string name, int credit)
{
    this->accnumber = num;
    this->accname = name;
    this->credit = credit;
}
void CreditAccount::Show()
{
    cout << "编号为：" << this->accnumber << endl;
    cout << "姓名为：" << this->accname << endl;
    cout << "信用额度为：" << this->credit << endl;
}
//**************************************
int main()
{
    Account A(1,"小米");
    CreditAccount C(2,"华为",100);
    A.Show();
    C.Show();
    return 0;
}