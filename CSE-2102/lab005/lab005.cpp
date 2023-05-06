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

double calculateTime(int numbers)
{
    generateNumbers(numbers);

    int array[numbers];
    readData("values.txt", array);

    clock_t start, end;
    start = clock();

    bubbleSort(array, numbers);

    end = clock();

    cout << "Elapsed time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec"
         << " for " << numbers << " numbers" << endl;
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
    using namespace matplot;

    int numbers, n = 10;
    std::vector<double> x;
    std::vector<double> y;

    for (int i = 0; i < n; i++)
    {
        numbers = (i + 1) * 10000;
        int time = calculateTime(numbers);
        x.push_back((double)(i + 1));
        y.push_back(time);
    }

    plot(x, y, "-o")->marker_indices({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    xlabel("Numbers of elements (x10000))");
    ylabel("Time Comsumed (sec)");

    grid("on");
    show();
    return 0;
}
