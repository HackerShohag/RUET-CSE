#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, (a % b));
}

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void primeFactorization(int n, int arr[])
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            arr[i] = count;
        }
    }
    if (n != 1)
        arr[n] = 1;
}

void bezoutCoefficients(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    bezoutCoefficients(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int moduloInverse(int a, int m)
{
    int x, y;
    bezoutCoefficients(a, m, x, y);
    return x;
}

void problemOne()
{
    int a1, a2, a3, m1, m2, m3;
    cout << "Enter the values: ";
    cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3;
    int M = m1 * m2 * m3;
    int M1 = M / m1, M2 = M / m2, M3 = M / m3;

    int y1 = moduloInverse(M1, m1);
    int y2 = moduloInverse(M2, m2);
    int y3 = moduloInverse(M3, m3);

    cout << "The value of x is: " << (a1 * M1 * y1 + a2 * M2 * y2 + a3 * M3 * y3) % M << endl;
}

void pseudoPrime(int n, int b)
{
    if (gcd(n, b) != 1 && !isPrime(b))
    {
        cout << "The number is not a pseudo prime." << endl;
        return;
    }

    int p[n + 1] = {0};
    primeFactorization(n, p);

    for (int i = 0; i < n; i++)
    {
        if (p[i] != 0)
        {
            int x = (n - 1) % (i - 1);
            if (fmod(pow(b, x), i) != 1)
            {
                cout << "The number is not a pseudo prime." << endl;
                return;
            }
        }
    }
    cout << "The number is a pseudo prime." << endl;
}

int main()
{
    // problemOne();
    pseudoPrime(91, 3);
    return 0;
}