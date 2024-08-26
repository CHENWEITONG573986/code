#include <iostream>
using namespace std;
class Salesman // 销售员
{
public:
    int num;                // 销售员号
    int quantity;           // 销售数量
    float price;            // 销售单价
    static int ALLquantity; // 总销售数量
    static float sum;       // 总销售额
    Salesman(){};
    Salesman(int num, int quantity, float price);
    static void ShowSum();
};

float Salesman::sum = 0;
int Salesman::ALLquantity = 0;

Salesman::Salesman(int num, int quantity, float price)
{
    // 初始化
    this->num = num;
    this->quantity = quantity;
    this->price = price;
    // 记录总销售数量
    this->ALLquantity += quantity;
    // 记录总销售额
    this->sum += quantity * price;
}

void Salesman::ShowSum()
{
    cout << "总销售额为：" << sum << endl;
    cout << "平均售价为：" << sum / float(ALLquantity) << endl;
}

int main()
{
    Salesman S1(101, 5, 23.5), S2(102, 12, 24.5), S3(103, 100, 21.5);
    Salesman::ShowSum();
}