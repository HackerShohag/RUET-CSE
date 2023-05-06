#include <iostream>

using namespace std;

template <typename type1, typename type2>
class A
{
private:
    type1 x;
    type2 y;

public:
    void setData(type1 x, type2 y)
    {
        this->y = y;
        this->x = x;
    }
    double Sum()
    {
        return this->x + this->y;
    }
};

int main()
{
    A<int, double> a;
    a.setData(21, 2.1);
    cout << a.Sum() << endl;

    A<int, int> b;
    b.setData(21, 2);
    cout << b.Sum() << endl;

    A<double, int> c;
    c.setData(3.1, 2);
    cout << c.Sum() << endl;

    A<double, double> d;
    d.setData(3.1, 2.1);
    cout << d.Sum() << endl;
}