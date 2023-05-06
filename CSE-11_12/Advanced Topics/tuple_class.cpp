#include <bits/stdc++.h>

using namespace std;

int main()
{
    tuple<int, string, double> tx = make_tuple(100, "Kamal", 3.5);

    cout << "The int data member is" << get<int>(tx) << endl;
    cout << "The string data member is" << get<string>(tx) << endl;
    cout << "The double data member is" << get<double>(tx) << endl;
    get<double>(tx) = 3.7;
    cout << "The modified double data member is" << get<double>(tx) << endl;

    tuple<int, string, double> bx = make_tuple(10, "Shohag", 7.7);

    tx.swap(bx);
    cout << "The tx data are" << get<int>(tx) << " " << get<string>(tx) << " " << get<double>(tx) << " " << endl;
    cout << "The bx data are" << get<int>(bx) << " " << get<string>(bx) << " " << get<double>(bx) << " " << endl;
}