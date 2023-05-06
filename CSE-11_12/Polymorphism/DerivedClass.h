#include "BaseClass.h"

using namespace std;

class DerivedClass : public BaseClass
{
private:
    /* data */
public:
    DerivedClass(/* args */);
    ~DerivedClass();

    // int getX()
    // {
    //     return this->x;
    // }
    int ge
    {
        return this->y;
    }
    int getZ()
    {
        return this->z;
    }
    int setY(int y)
    {
        this->y = y;
    }
    int setZ(int z)
    {
        this->z = z;
    }
};

DerivedClass::DerivedClass(/* args */)
{
    cout << "Derived class has been constructed." << endl;
}

DerivedClass::~DerivedClass()
{
    cout << "Derived class has been distructed." << endl;
}
