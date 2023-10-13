#include <bits/stdc++.h>
#include "datageneratortools.h"

using namespace std;

int linear_search(int x, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int binary_search(int x, int array[], int size, int *steps)
{
    int l = 0, h = size - 1, c;

    while (l <= h)
    {
        c = (l + h) / 2;
        if (array[c] == x)
            return c;

        if (array[c] < x)
            l = c + 1;
        if (array[c] > x)
            h = c - 1;

        (*steps)++;
    }
    return -1;
}

int main()
{
    int numbers, n = 5;
    for (int i = 0; i < n; i++)
    {
        FILE *file;
        numbers = (i + 1) * 10000;
        int x = rand() % 1000, array[numbers];
        string filename = "lab02_assets/search_";
        filename.append(to_string(i + 1));
        filename.append(".txt");

        if (file = fopen(filename.c_str(), "r"))
        {
            fclose(file);
            printf("Files exist. Skipping data generate.\n");
        }
        else
        {
            generateNumbers(numbers, filename);
            printf("Files deosn't exist. Generating data.\n");
        }

        readData(filename, array);

        int pos = linear_search(x, array, numbers);
        cout << "For " << numbers << " numbers: "
             << "for Linear Search Algorithm:"
             << "\tKey: " << pos << "\tValue: " << array[pos] << "\tTotal Steps: " << (pos == -1 ? numbers : (pos + 1)) << endl;

        sort(array, array + numbers);

        int p = 0;
        int *steps;
        steps = &p;
        pos = binary_search(x, array, numbers, steps);
        cout << "For " << numbers << " numbers: "
             << "for Binary Search Algorithm:"
             << "\tKey: " << pos << "\tValue: " << array[pos] << "\tTotal Steps: " << (*steps) << endl
             << endl;
    }
}
