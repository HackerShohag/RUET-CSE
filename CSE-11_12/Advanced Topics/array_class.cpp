#include <bits/stdc++.h>

using namespace std;

int main()
{
    array<int, 6> ax{10, 60, 30, 70, 20};
    cout << "Third element using at() is " << ax.at(2) << endl;
    cout << "First element using front() is " << ax.front() << endl;
    cout << "Last element using back() is " << ax.back() << endl;
    ax.fill(11);
    if (ax.empty())
        cout << "The array is empty.\n";
    else
        cout << "The array is not empty.\n";

    cout << "The size of the ax is " << ax.size() << "." << endl;
    cout << "The maximum size of the ax is " << ax.max_size() << "." << endl;
    cout << "The address of the first element of ax using begin() is " << ax.begin() << "." << endl;
    cout << "The address of the last element of ax using begin() is " << ax.end() - 1 << "." << endl;

    // swaping the last 2 values
    // ax.swap();
}