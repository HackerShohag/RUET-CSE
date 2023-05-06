#include <bits/stdc++.h>
#include <matplot/matplot.h>

// namespace plt = matplotlibcpp;
using namespace std;

void bubbleSort(int array[], int size)
{
    for (int step = 0; step < size; ++step)
    {
        for (int i = 0; i < size - step; ++i)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << endl;
    }
    cout << "\n";
}

void generateNumbers(int count)
{
    ofstream file;
    file.open("values.txt");

    for (int i = 0; i < count; i++)
    {
        file << rand() << " ";
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

void calculateTime(int numbers)
{
    generateNumbers(numbers);

    int array[numbers];
    readData("values.txt", array);

    clock_t start;
    start = clock();

    bubbleSort(array, numbers);

    cout << "Elapsed time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "sec"
         << " for " << numbers << " numbers" << endl;
}

int main()
{
    // for (int i = 0; i < 10; i++)
    // {
    //     calculateTime((i + 1) * 10000);
    // }

    using namespace matplot;

    std::vector<double> x = iota(0, 1000);
    std::vector<double> y = transform(x, [](auto x)
                                      { return log(x); });
    semilogx(x, y);

    show();
    return 0;
}
