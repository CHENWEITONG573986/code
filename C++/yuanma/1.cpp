#include <iostream>
using namespace std;
class City
{
private:
    City(int num, string name) : num(num), name(name) {};

public:
    int num;
    string name;
    static const City *BEIJIN;
};
const City *City::BEIJIN = new City(101, "dawd");
int main()
{
    cout << sizeof(City) << endl;
    cout << City::BEIJIN->name << endl;
    cout << City::BEIJIN->num << endl;
    auto c = [](auto a, auto b)
    {
        return a > b;
    };
}
