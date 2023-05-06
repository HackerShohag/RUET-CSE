#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>

using namespace std;

void Display(list<int> l)
{
    for (auto it = l.begin(); it < l.end(); it++)
    {
        /* code */
    }
}

int main()
{
    list<int> li;
    li.push_back(12);
    li.push_back(10);
    li.push_back(30);
    li.push_back(50);
    li.push_back(40);
    li.push_back(78);
    li.push_back(28);
    li.push_back(80);

    li.push_front(21);
    li.push_front(31);
}