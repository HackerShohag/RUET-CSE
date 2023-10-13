#include <iostream>
#include <chrono>
#include "datageneratortools.h"

using namespace std;

int minmaxIterative(int array[], int size, int *min, int *max)
{
    *max = *min = array[0];

    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] > *max)
            *max = array[i];
        else if (array[i] < *min)
            *min = array[i];
    }
    return i;
}

int minmaxRecursive(int array[], int start, int end, int *min, int *max, int *steps)
{
    if (start == end)
    {
        if (array[start] > *max)
            *max = array[start];
        else if (array[start] < *min)
            *min = array[start];
        return 1;
    }

    int mid = (start + end) / 2;
    minmaxRecursive(array, start, mid, min, max, steps);
    minmaxRecursive(array, mid + 1, end, min, max, steps);
}

int main()
{
    using namespace std::chrono;
    using fsec = duration<float>;
    using ftp = time_point<steady_clock, fsec>;

    int numbers, n = 5;
    for (int i = 0; i < n; i++)
    {
        FILE *file;
        numbers = (i + 1) * 10000;
        int x = rand() % 1000, array[numbers];
        string filename = "lab02_assets/search_";
        filename.append(to_string(i + 1));
        filename.append(".txt");

        readData(filename, array);

        int min, max, steps = 0;

        auto start1 = steady_clock::now();
        steps = minmaxIterative(array, numbers, &min, &max);
        auto end1 = steady_clock::now();
        cout << "Iterative for " << numbers << " numbers with " << (end1 - start1).count() << " ms" << endl;

        auto start2 = steady_clock::now();
        minmaxRecursive(array, 0, numbers - 1, &min, &max, &steps);
        auto end2 = steady_clock::now();
        cout << "Recursive for " << numbers << " numbers with " << (end2 - start2).count() << " ms\n"
             << endl;
    }

    return 0;
}