#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
    }
    Person(int a)
    {
        m_a = new int(a);
    }
    ~Person()
    {
        if (m_a != NULL)
        {
            delete m_a;
            m_a = NULL;
        }
    }
    Person &operator=(Person &p)
    {
        if (m_a != NULL)
        {
            delete m_a;
            m_a = NULL;
        }
        m_a = new int(*p.m_a);
        return *this;
    }
    int *m_a;
};

ostream &operator<<(ostream &cout, Person p)
{
    cout << "a=" << *p.m_a;
    return cout;
}

void test()
{
    Person p1(10);
    //p2 = p1;
    cout << p1 << endl;
    //cout << p2 << endl;
}

int main()
{
    test();
}