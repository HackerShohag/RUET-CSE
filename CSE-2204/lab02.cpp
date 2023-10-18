#include <iostream>
#include "functionInput.h"

using namespace std;

double newtonRapsonMethod(int x, double error)
{
    double x1 = x - function(x) / functionDerivative(x);
    double x2 = x1 - function(x1) / functionDerivative(x1);

    while (abs(x2 - x1) > error)
    {
        x1 = x2;
        x2 = x1 - function(x1) / functionDerivative(x1);
        cout << "x1: " << x1 << "\tx2: " << x2 << "\n";
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

    cout << "Root by Newron-Rapson method: " << newtonRapsonMethod(a, 0.0001) << "\n";
}