#include <bits/stdc++.h>

using namespace std;

int main()
{
    pair<int, string> px;
    px = make_pair(10, "Rajshahi");
    cout << "The first data member is " << px.first << endl;
    cout << "The second data member is " << px.second << endl;

    get<int>(px) = 20;
    pair<int, string> bx = make_pair(30, "Rangpur");

    px.swap(bx);

    cout << "bx data: " << get<int>(bx) << " " << get<string>(bx) << endl;
    cout << "px data: " << get<int>(px) << " " << get<string>(px) << endl;
}