#include "DerivedClass.h"

class DerivedClass2 : public DerivedClass
{
private:
    /* data */
public:
    DerivedClass2(/* args */);
    ~DerivedClass2();
};

DerivedClass2::DerivedClass2(/* args */)
{
    cout << "Derived class 2 has been constructed." << endl;
}

DerivedClass2::~DerivedClass2()
{
    cout << "Derived class 2 has been distructed." << endl;
}
