#include <iostream>
using namespace std;
class Salesman
{
private:
    int num;
    int quantity;
    float price;
    static float discount;
    static int sum;
    static float sales;

public:
    Salesman(){};
    Salesman(int num, int quantity, float price)
        : num(num), quantity(quantity), price(price)
    {
        sum += quantity;
        sales += (quantity * price);
    };
    static int getsum();
    static float getAveragePrice();
    ~Salesman(){};
};
float Salesman::discount = 0;
int Salesman::sum = 0;
float Salesman::sales = 0;

int Salesman::getsum()
{
    return sum;
}

float Salesman::getAveragePrice()
{
    return sales / sum;
}

int main()
{
    Salesman S1(101, 5, 23.5), S2(102, 12, 24.5), S3(103, 100, 21.5);
    cout << Salesman::getsum() << endl;
    cout << Salesman::getAveragePrice() << endl;
    system("pause");
    return 0;
}