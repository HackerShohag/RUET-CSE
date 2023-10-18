#include <iostream>
#include <chrono>

using namespace std;

int SakibsAlgorithm(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int k;
    long long size;
    cout << "Enter the number of test cases:";
    cin >> size;
    srand(time(0));

    auto start = std::chrono::high_resolution_clock::now();
    for (int it = 0; it < size; it++)
    {
        cout << "Case #" << it + 1 << ": ";
        cin >> k;
        cout << "Output of Sakib's Algorithm: " << SakibsAlgorithm(k) << endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Run time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}