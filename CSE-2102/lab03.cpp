#include <bits/stdc++.h>
#include "setOperations.h"

using namespace std;

template <size_t N>

void printSet(int (&a)[N])
{
    cout << "{";
    for (int i : a)
    {
        if (i != a[0])
            cout << ", ";
        cout << i;
    }
    cout << "}\n";
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    int b[3] = {1, 3, 9};

    printSet(a);
    printSet(b);

    setUnion<4, 3>(a, b);
    // printSet();

    // cout << "\nIntersection: "; printSet(setIntersection(a, b));
    // cout << "\nComplement: "; printSet(setComplement(a, b));
    // cout << "\nDifference: "; printSet(setDifference(a, b));
    // cout << "\nSymmetric difference: "; printSet(setDifference(a, b));
    return 0;
}