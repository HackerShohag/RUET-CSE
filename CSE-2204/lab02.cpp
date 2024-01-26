#include <iostream>
#include "headers/functionInput.h"

using namespace std;

double newtonRapsonMethod(double x, double error)
{
    double x1 = x - function(x) / functionDerivative(x);
    double x2 = x1 - function(x1) / functionDerivative(x1);

    cout << "x0: " << x << "\tx1: " << x1 << "\n";

    int i = 1;
    while (abs(x2 - x1) > error)
    {
        x1 = x2;
        x2 = x1 - function(x1) / functionDerivative(x1);
        cout << "x" << i << ": " << x1 << "\tx" << (i + 1) << ": " << x2 << "\n";
        i++;
    }

    return x2;
}

double phiFunction(double x, int coeff[], int degree)
{
    double sum = 0;
    for (int i = 0; i <= degree; i++)
    {
        sum += coeff[i] * pow(x, i);
    }
    return sum;
}

double iterarionMethod(double x, double error)
{
    int degree;
    cout << "Enter degree for phi function: ";
    cin >> degree;
    int coeff[degree + 1];
    cout << "Enter " << degree + 1 << " Coefficients: ";
    for (int i = 0; i <= degree; i++)
        cin >> coeff[i];

    double x1 = phiFunction(x, coeff, degree);
    double x2 = phiFunction(x1, coeff, degree);

    while (abs(x2 - x1) > error)
    {
        x1 = x2;
        x2 = phiFunction(x1, coeff, degree);
        cout << "x1: " << x1 << "\tx2: " << x2 << "\n";
    }

    return x2;
}

int main()
{
    takeInputForFunction();
    double a;

    cout << "Enter guess: ";
    cin >> a;

    cout << "\n1. Newton Rapson Method\n2. Iteration Method\n";
    cout << "Choose the method you want to use: ";

    int choice;
    cin >> choice;
    switch (choice)
    {
        {
        case 1:
        {
            double sol = newtonRapsonMethod(a, 0.0001);
            cout << "The solution using Newton-Rapson Method: " << sol << endl;
            break;
        }

        case 2:
        {
            double sol = iterarionMethod(a, 0.0001);
            cout << "The solution using Iteration Method: " << sol << endl;
            break;
        }

        default:
            break;
        }
    }
}
