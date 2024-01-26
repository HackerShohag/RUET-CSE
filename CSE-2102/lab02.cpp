#include <iostream>
#include "headers/operations.h"

using namespace std;

void gameOfChomp()
{
    int x, y, total = 20, delegate = 5;
    int tmp = rand() % (delegate - 1) + 1;

    cout << "How do you want to play as?\n\t1. Player 1\n\t2. Player 2\nEnter your choice: ";
    cin >> x;

    if (x == 1)
    {
        while (total > 0)
        {
            cout << "Enter your move: ";
            cin >> y;
            while (y < 1 || y > 4)
            {
                cout << "Please enter a valid move (between 1 to 4): ";
                cin >> y;
            }
            total -= y;
            if (total == 0)
            {
                cout << "\nPlayer 1 won the game.\n";
                break;
            }
            cout << "Player 2 chose " << (delegate - y) << "\t";
            total -= (delegate - y);

            if (total == 0)
            {
                cout << "\nPlayer 2 won the game.\n";
                break;
            }
            cout << "balls left " << total << endl;
        }
    }
    else
    {
        while (total > 0)
        {
            cout << "Player 1 chose " << tmp << "\t";
            total -= tmp;
            if (total == 0)
            {
                cout << "\nPlayer 1 won the game.\n";
                break;
            }
            cout << "Enter your move: ";
            cin >> y;
            while (y < 1 || y > 4)
            {
                cout << "Please enter a valid move (between 1 to 4): ";
                cin >> y;
            }
            total -= y;
            if (total == 0)
            {
                cout << "\nPlayer 2 won the game.\n";
                break;
            }

            tmp = total % delegate;
            if (!tmp)
                tmp = rand() % (delegate - 1) + 1;
            cout << "balls left " << total << endl;
        }
    }
}

bool checkCondition(int *x, int *y, char operation, char comparison, int value)
{
    int n = sizeof(x) / sizeof(int);
    int m = sizeof(y) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        bool tmp = false;
        for (int j = 0; j < m; j++)
        {
            if (operation == '+' && comparison == '>')
            {
                if ((x[i] + y[j]) > value)
                {
                    tmp = true;
                    break;
                }
            }
            if (operation == '+' && comparison == '<')
            {
                if ((x[i] + y[j]) < value)
                {
                    tmp = true;
                    break;
                }
            }
            if (operation == '+' && comparison == '=')
            {
                if ((x[i] + y[j]) == value)
                {
                    tmp = true;
                    break;
                }
            }
            if (operation == '-' && comparison == '>')
            {
                if ((x[i] - y[j]) > value)
                {
                    tmp = true;
                    break;
                }
            }
            if (operation == '-' && comparison == '<')
            {
                if ((x[i] + y[j]) < value)
                {
                    tmp = true;
                    break;
                }
            }
            if (operation == '-' && comparison == '=')
            {
                if ((x[i] + y[j]) > value)
                {
                    tmp = true;
                    break;
                }
            }
        }
        if (!tmp) return false;
    }
    return true;
}

void problemTwo()
{
    string condition;
    cin >> condition;

    bool t;
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

    if (condition[0] == 'x')
        t = checkCondition(x, y, condition[1], condition[3], condition[4] - '0');
    else if (condition[0] == 'y')
        t = checkCondition(y, x, condition[1], condition[3], condition[4] - '0');

    cout << (t ? 'T' : 'F') << endl;
    return;
}

int main()
{
    // gameOfChomp();
    problemTwo();
}