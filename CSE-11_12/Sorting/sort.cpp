#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int size)
{
    int minimum = arr[0], minimumIndex = 0, tmp = 0;
    for (int i = 0; i < size; i++)
    {
        minimum = arr[i];
        for (int j = i; j < size; j++)
        {
            tmp = minimum;
            minimum = minimum > arr[j] ? arr[j] : minimum;
            minimumIndex = minimum != tmp ? j : minimumIndex;
        }
        if (arr[i] > arr[minimumIndex])
            swap(arr[i], arr[minimumIndex]);
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
                // cout << "Swapping between " << arr[i] << " " << arr[j] <<endl;
                i--;
            }
        }
    }
}

void quickSort(int arr, int size) {

}

void mergeSort(int arr, int low, int high) {
    if(low<high) {
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(low, mid, high);
    }
}
void merge(int arr, int low, int mid, int high) {
    int i = 1;
    int j = mid+1;
    int k = low;
    while (i<=mid && j<=high)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
        }
    }
}

void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 78, 32, 90, 20, 19, 25};
    insertionSort(arr, 7);
    Display(arr, 7);
    return 0;
}