#include <iostream>
using namespace std;

double leastSquare(double x[], double y[], int n, double *a1)
{
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    *a1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    return (sumY - *a1 * sumX) / n;
}

int main()
{
    int n;
    cout << "Enter the number of values: ";
    cin >> n;
    double x[n], y[n];

    cout << "Enter the values of X: ";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter the values of Y: ";
    for (int i = 0; i < n; i++)
        cin >> y[i];

    double a0, a1;
    a0 = leastSquare(x, y, n, &a1);

    cout << "\nThe value of a0 is " << a0 << " and the value of a1 is " << a1 << endl;
    cout << "The equation is: y = " << a0 << " + " << a1 << "x" << endl;
    return 0;
}