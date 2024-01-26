#include <iostream>

using namespace std;

double function(double x)
{
    return 1 / (1 + x);
}

void generateTable(double x[], double y[], double a, double b, int n)
{
    double h = (b - a) / n;
    x[0] = a;
    y[0] = function(x[0]);

    for (int i = 1; i < n; i++)
    {
        x[i] = x[0] + i * h;
        y[i] = function(x[i]);
    }
}

double TrapezoidalRule(double y[], double h, int n)
{
    double sum = 0;

    for (int i = 0; i < (n - 1); i++)
    {
        sum += (h / 2) * (y[i] + y[i + 1]);
    }

    return sum;
}

double SimpsonsOneThirdRule(double y[], double h, int n)
{
    double sum = 0;

    for (int i = 0; i < (n - 2); i += 2)
    {
        sum += (h / 3) * (y[i] + 4 * y[i + 1] + y[i + 2]);
    }

    return sum;
}

double SimpsonsThreeEightRule(double y[], double h, int n)
{
    double sum = 0;

    for (int i = 0; i < (n - 3); i += 3)
    {
        sum += ((3 * h) / 8) * (y[i] + 3 * y[i + 1] + 3 * y[i + 2] + y[i + 3]);
    }

    return sum;
}

int main()
{
    int n = 100000;
    double x[n + 1], y[n + 1];
    double a, b, h;

    cout << "Enter Lower Limit: ";
    cin >> a;
    cout << "Enter Upper Limit: ";
    cin >> b;
    cout << "Enter Interval: ";
    cin >> n;

    // a = 0;
    // b = 1;
    h = (b - a) / n;

    generateTable(x, y, a, b, n);

    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << "\t";
        cout << "y[" << i << "] = " << y[i] << endl;
    }

    double TrapezoidalIntegration = TrapezoidalRule(y, h, n);
    double SimpsonsOneThirdIntegration = SimpsonsOneThirdRule(y, h, n);
    double SimpsonsThreeEightIntegration = SimpsonsThreeEightRule(y, h, n);

    cout << "Trapezoidal Integration of defined function in limit " << a << " to " << b << " is: " << TrapezoidalIntegration << endl;
    cout << "Simpson's 1/3 Integration of defined function in limit " << a << " to " << b << " is: " << SimpsonsOneThirdIntegration << endl;
    cout << "Simpson's 3/8 Integration of defined function in limit " << a << " to " << b << " is: " << SimpsonsThreeEightIntegration << endl;
}