#include <iostream>
#include "headers/operations.h"

using namespace std;

void problemOne()
{
    bool p[] = {true, false};
    bool q[] = {true, false};
    cout << "p\tq\t¬p∧(p→q)\tp∨(¬q→p)\n";
    for (auto i : p)
    {
        for (auto j : q)
            cout << deform(i) << "\t" << deform(j) << "\t" << deform((!i and (implies(i, j)))) << "\t\t" << deform((i or (implies(!(j), i)))) << "\n";
    }
}

void problemTwo()
{
    int n, m;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cin >> m;
    int y[m];
    for (int i = 0; i < m; i++)
    {
        cin >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        bool tmp = false;
        for (int j = 0; j < m; j++)
        {
            if ((x[i] + y[j]) > 0)
            {
                tmp = true;
                break;
            }
        }
        if (!tmp) {
            cout << "F\n";
            return ;
        }
    }
    cout << "T\n";
    return ;
}

int main()
{

    // problemOne();
    problemTwo();
}