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

void merge(int array[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = array[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(array, start, mid);
        mergesort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void quicksort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = array[end];
        int i = start - 1;

        for (int j = start; j <= end - 1; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                swap(array[i], array[j]);
            }
        }

        swap(array[i + 1], array[end]);

        int partitionIndex = i + 1;

        quicksort(array, start, partitionIndex - 1);
        quicksort(array, partitionIndex + 1, end);
    }
}

int main()
{
    using namespace std::chrono;
    using fsec = duration<float>;
    using ftp = time_point<steady_clock, fsec>;

    int numbers, n = 9;
    int nums[9] = {1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000};

    for (int i = 0; i < n; i++)
    {
        FILE *file;
        numbers = nums[i];
        int x = rand() % 1000, array[numbers];
        string filename = "lab03_assets/search_";
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

        int min, max, steps = 0;

        auto start1 = steady_clock::now();
        steps = minmaxIterative(array, numbers, &min, &max);
        auto end1 = steady_clock::now();
        cout << "Iterative for " << numbers << " numbers with " << (end1 - start1).count() << " ms" << endl;

        auto start2 = steady_clock::now();
        minmaxRecursive(array, 0, numbers - 1, &min, &max, &steps);
        auto end2 = steady_clock::now();
        cout << "Recursive for " << numbers << " numbers with " << (end2 - start2).count() << " ms" << endl;

        auto start3 = steady_clock::now();
        mergesort(array, 0, numbers);
        auto end3 = steady_clock::now();
        cout << "Merge sort for " << numbers << " numbers with " << (end3 - start3).count() << " ms" << endl;

        auto start4 = steady_clock::now();
        quicksort(array, 0, numbers);
        auto end4 = steady_clock::now();
        cout << "Quick sort for " << numbers << " numbers with " << (end4 - start4).count() << " ms\n"
             << endl;
    }

    return 0;
}