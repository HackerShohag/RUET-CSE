#include <iostream>
using namespace std;

double NewtonForward(double x[], double y[], int n, double p)
{
    double dely[n][n], a = x[0], h = x[1] - x[0], u, y0;

    for (int i = 0; i < n; i++)
        dely[i][0] = y[i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            dely[j][i] = dely[j + 1][i - 1] - dely[j][i - 1];

    int k = 0;
    while (a - p > h)
    {
        a = x[k];
        k++;
    }
    u = (p - a) / h;
    y0 = dely[0][0];
    double tempU = u;

    for (int i = 1; i < (n - k); i++)
    {
        if (i != 1)
            tempU = tempU * (u - i + 1);

        tempU = tempU / (double)i;
        y0 += tempU * dely[k][i];
    }
    return y0;
}

double NewtonBackward(double x[], double y[], int n, double p)
{
    double dely[n][n], a = x[n - 1], h = x[1] - x[0], u, y0;

    for (int i = 0; i < n; i++)
        dely[i][0] = y[i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            dely[j][i] = dely[j + 1][i - 1] - dely[j][i - 1];

    int k = 0;
    while (a - p > h)
    {
        a = x[k];
        k++;
    }
    u = (p - a) / h;
    y0 = dely[n - 1][0];
    double tempU = u;

    for (int i = 1; i < (n - k); i++)
    {
        if (i != 1)
            tempU = tempU * (u + i - 1);

        tempU = tempU / (double)i;
        y0 += tempU * dely[n - k - i - 1][i];
    }
    return y0;
}

void takeInput(double *x, double *y, int &n, double &x0)
{
    cout << "Enter the number of data points: ";
    cin >> n;
    cout << "Enter the values of x: ";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter the values of y: ";
    for (int i = 0; i < n; i++)
        cin >> y[i];
    cout << endl;

    cout << "Enter the value of x for which y is to be found: ";
    cin >> x0;
}

int main()
{
    int input = 0;
    while (input != 3)
    {
        // take all the inputs
        int n = 0;
        double x[10000], y[10000], x0;

        // take the choice
        cout << "1. Newton Forward" << endl;
        cout << "2. Newton Backward" << endl;
        cout << "3. Exit" << endl
             << endl;
        cout << "Note: All the data must be equally spaced" << endl;
        cout << "Enter your choice: ";
        cin >> input;
        cout << endl;

        switch (input)
        {
        case 1:
        {
            takeInput(x, y, n, x0);
            double y0 = NewtonForward(x, y, n, x0);
            cout << "The value of y at x = " << x0 << " is " << y0 << endl
                 << endl
                 << endl;
            break;
        }
        case 2:
        {
            takeInput(x, y, n, x0);
            double y0 = NewtonBackward(x, y, n, x0);
            cout << "The value of y at x = " << x0 << " is " << y0 << endl
                 << endl
                 << endl;
            break;
        }
        case 3:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
            cout << endl
                 << endl;
        }
    }
}