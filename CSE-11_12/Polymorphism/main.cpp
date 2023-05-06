#include "DerivedClass2.h"
#include <iostream>

using namespace std;

int main()
{
    DerivedClass2 a;
    a.setY(4);
    a.setZ(10);
    cout << "Y: " << a.getY() << "\tZ: " << a.getZ() << endl;
}