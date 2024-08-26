#include <iostream>
using namespace std;
class Boat
{
public:
    static int weight;
    friend void getTotalWeight();
};
int Boat::weight = 100;
class Car
{
public:
    static int weight;
    friend void getTotalWeight();
};
int Car::weight = 100;
void getTotalWeight()
{
    cout << "二者重量之和为：" << Boat::weight + Car::weight << endl;
}
int main()
{
    getTotalWeight();
}