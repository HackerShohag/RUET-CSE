#include <bits/stdc++.h>

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

void generateNumbers(int count, string filename)
{
    ofstream file;
    file.open(filename);

    for (int i = 0; i < count; i++)
    {
        file << rand() % 1000 << " ";
    }
    file.close();
}

void readData(string filename, int array[])
{
    ifstream file;
    file.open(filename);

    int i = 0;
    while (file >> array[i])
    {
        i++;
    }
    file.close();
}

int main()
{
    int numbers, n = 5;
    for (int i = 0; i < n; i++)
    {
        numbers = (i + 1) * 10000;
        int x = rand() % 1000, array[numbers];

        string filename = "lab02_assets/search_";
        filename.append(to_string(i + 1));
        filename.append(".txt");

        generateNumbers(numbers, filename);
        readData(filename, array);
        sort(array, array + numbers);

        int pos = linear_search(x, array, numbers);
        cout << "For " << numbers << " numbers: "
             << "for Linear Search Algorithm:"
             << "\tKey: " << pos << "\tValue: " << array[pos] << "\tTotal Steps: " << (pos == -1 ? numbers : (pos + 1)) << endl;

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
