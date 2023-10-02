#include <iostream>

#define MAX_ITERATION 100

using namespace std;

/**
 * Calculates the value of a cubic function at a given point.
 *
 * @param x The point at which to evaluate the function.
 * @return The value of the function at the given point.
 */
double function(double x)
{
    return x * x * x - 2 * x - 5;
}

/**
 * Calculates the root of a function using the bisection method.
 *
 * @param a The lower bound of the interval.
 * @param b The upper bound of the interval.
 * @param print If true, prints the iteration table.
 * @return The root of the function.
 */
double rootByBisection(double a, double b, bool print = false)
{
    int i = 0;
    double error = abs(a - b), c;

    while (abs(error) > 0.0001)
    {
        if (print)
            cout << i + 1 << "\t|\t" << a << "\t|\t" << b << "\t|\t" << c << "\t\t|\t" << function(c) << "\t\t|\t" << error << "\n";

        c = (a + b) / 2;
        if (function(a) * function(c) < 0)
            b = c;
        else
            a = c;

        error = abs(a - b);

        if (i > MAX_ITERATION)
            break;
        i++;
    }
    return c;
}

/**
 * Calculates the root of a function using the false position method.
 * @param a The lower bound of the interval.
 * @param b The upper bound of the interval.
 * @param print If true, prints the iteration table.
 * @return The root of the function.
 */
double rootByFalsePosition(double a, double b, bool print = false)
{
    int i = 0;
    double c;

    while (abs(function(c)) > 0.0001)
    {
        if (print)
            cout << i + 1 << "\t|\t" << a << "\t|\t" << b << "\t|\t" << c << "\t\t|\t" << function(c) << "\t\t|\t" << function(c) * 100 << "%\n";

        c = b - function(b) * (b - a) / (function(b) - function(a));

        if (function(a) * function(c) < 0)
            b = c;
        else
            a = c;

        if (i > MAX_ITERATION)
            break;
        i++;
    }
    return c;
}

int main()
{
    int choice;
    double a = -1, b = 1;

    while (function(a) * function(b) > 0)
    {
        function(b) > function(a) ? b++ : a--;
    }

    // cout << "a: " << a << "\tb: " << b << "\n";

    cout << "Menu Program: \n";
    cout << "\t1. Bisection Method\n";
    cout << "\t2. False Position Method\n";
    cout << "\t3. Compare Both Methods\n";
    cout << "Enter Your Choice: ";
    cin >> choice;

    cout << "\n\nn\t|\ta\t|\tb\t|\tx\t\t|\tf(x)\t\t|\terror\n";
    cout << "---------------------------------------------------------------------------------------------------------------------\n";

    switch (choice)
    {
    case 1:
        rootByBisection(a, b, true);
        break;
    case 2:
        rootByFalsePosition(a, b, true);
        break;
    case 3:
        cout << "Bisection Method: " << rootByBisection(a, b) << " with error: " << function(rootByBisection(a, b)) * 100 << "%\n";
        cout << "False Position Method: " << rootByFalsePosition(a, b) << " with error: " << function(rootByFalsePosition(a, b)) * 100 << "%\n";
        break;
    }
}