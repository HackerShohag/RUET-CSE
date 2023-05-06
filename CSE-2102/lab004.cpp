#include <iostream>

using namespace std;

long long power(int a, int b)
{
    int s = a;
    for (int i = 1; i < b; i++)
    {
        s *= a;
    }
    return s;
}

long long summationOne()
{
    long long sum = 0;
    for (int j = 1; j <= 3; j++)
    {
        for (int i = 0; i <= 8; i++)
        {
            sum += 3 * i + 4 * j;
        }
    }
    return sum;
}

long long summationTwo()
{
    long long sum = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            sum += power(2, i) + power(3, j);
        }
    }
    return sum;
}

int main()
{
    cout << "Summation of (i) ∑j(1,3) ∑i(0,8) (3i + 4j) is: " << summationOne() << endl;
    cout << "Summation of (ii) ∑i(1,3) ∑j(0,8) (3i + 4j) is: " << summationTwo() << endl;
}