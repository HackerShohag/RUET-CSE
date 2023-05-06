#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> qu;
    qu.push(21);
    qu.push(31);
    qu.push(51);
    qu.pop();
    cout << "Front element: " << qu.front() << endl;
    cout << "Rear element: " << qu.back() << endl;

    if (qu.empty())
        cout << "The stack is empty.\n";
    else
        cout << "The stack is not empty.\n";
}