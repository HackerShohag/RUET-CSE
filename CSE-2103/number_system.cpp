#include <iostream>

using namespace std;

int fromAnyBaseToAnyBase(int number, int currentBase, int targetBase)
{
    int result = 0;
    int multiplier = 1;
    while (number > 0)
    {
        int digit = number % targetBase;
        number /= targetBase;
        result += digit * multiplier;
        multiplier *= currentBase;
    }
    return result;
}

int main()
{
    cout << "Any Based Number: " << fromAnyBaseToAnyBase(2, 10, 10) << endl;
    cout << "Reveresed Number: " << fromAnyBaseToAnyBase(7, 8, 12) << endl;
}