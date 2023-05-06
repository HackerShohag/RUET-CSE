#include <iostream>

using namespace std;

class BaseClass
{
private:
    int x;
protected:
    int y;
public:
    int z;
    BaseClass();
    ~BaseClass();
};

BaseClass::BaseClass(/* args */)
{
    cout << "Base class has been constructed." << endl;
}

BaseClass::~BaseClass()
{
    cout << "Base class has been distructed." << endl;
}
