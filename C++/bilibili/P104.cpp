#include<iostream>
using namespace std;

class Cube
{
public:
    int Area()
    {
        return 2*(l*w+l*h+w*h);
    }
    int Volume()
    {
        return l*w*h;
    }
    void setLWH(int L,int W,int H)
    {
        l=L;
        w=W;
        h=H;
    }
    int getL()
    {
        return l;
    }
    int getW()
    {
        return w;
    }
    int getH()
    {
        return h;
    }
    bool Judgment(Cube &c)
    {
        if(l==c.getL()&&w==c.getW()&&h==c.getH())
        {
            return true;
        }
        return false;
    }
private:
    int l,w,h;
};

bool Judgment(Cube &c1,Cube &c2)
{
    if(c1.getL()==c2.getL()&&c1.getW()==c2.getW()&&c1.getH()==c2.getH())
    {
        return true;
    }
    return false;
}

int main()
{
    Cube c1,c2;
    c1.setLWH(5,6,7);
    c2.setLWH(5,6,7);
    cout << c1.getL() << " " << c1.getW() << " " << c1.getH() << endl;
    cout << "面积=" << c1.Area() << endl;
    cout << "体积=" << c1.Volume() << endl;
    bool a=Judgment(c1,c2); //全局函数
    if(a)
        cout << "c1与c2相同" << endl;
    else
        cout << "c1与c2不同" << endl;
    a=c1.Judgment(c2); //成员函数
    if(a)
        cout << "c1与c2相同" << endl;
    else
        cout << "c1与c2不同" << endl;
    return 0;
}