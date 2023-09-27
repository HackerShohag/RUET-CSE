#include <bits/stdc++.h>

using namespace std;

void sieveOfEratosthenes(int n)
{
    int array[n + 1] = {0};
    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = 2; i * j <= n; j++)
        {
            array[i * j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (array[i] == 0)
            cout << i << " ";
    }
    cout << endl;
}

int gcdUsingEuclidean(int a, int b)
{
    if (b == 0)
        return a;
    return gcdUsingEuclidean(b, a % b);
}

int bezout(int a, int b, int prev_a, int prev_b)
{
    if (b == 0)
    {
        cout << "Bezout Coefficients are: " << prev_a << " and " << prev_b << endl;
        return a;
    }
    return bezout(b, a % b, prev_b, prev_a - (a / b) * prev_b);
}

void bezoutCoefficient(int a, int b)
{
    bezout(a, b, 1, 0);
}
// {
//     int prev_a, prev_b;
//     if (b == 0)
//         return a;
//     return bezoutCoefficient(b, a % b);
// }

void primeFactorization(int n)
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
            cout << i << "^" << count << " ";
        }
    }
    if (n != 1)
        cout << n << "^" << 1 << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter a value to find prime numbers: ";
    cin >> n;

    cout << "Prime numbers upto " << n << " is: ";
    sieveOfEratosthenes(n);

    cout << "Enter a value for prime factorization: ";
    cin >> n;
    cout << "Prime factorization of " << n << " is: " << endl;

    int a, b;
    cout << "Enter two values to find GCD: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcdUsingEuclidean(a, b) << endl;
    bezoutCoefficient(a, b);
}