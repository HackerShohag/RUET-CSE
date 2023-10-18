#ifndef FUNCTIONINPUT_H
#define FUNCTIONINPUT_H
#include <iostream>
#include <cmath>

using namespace std;

int degree;
int *coefficients = new int[degree + 1];

void takeInputForFunction()
{
    int deg;
    cout << "Enter the degree of the polynomial: ";
    cin >> deg;
    int *coef = new int[deg + 1];
    cout << "Enter " << deg + 1 << " coefficients of the polynomial: ";
    for (int i = 0; i <= deg; i++)
        cin >> coef[i];
    delete[] coefficients; // free the previously allocated memory
    coefficients = coef;
    degree = deg;
}

double function(double x)
{
    double sum = 0;
    for (int i = 0; i <= degree; i++)
    {
        sum += coefficients[i] * pow(x, i);
    }
    return sum;
}

double functionDerivative(double x)
{
    double sum = 0;
    for (int i = 1; i <= degree; i++)
        sum += i * coefficients[i] * pow(x, i - 1);
    return sum;
}

#endif // !FUNCTIONINPUT_H