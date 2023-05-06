#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int arr[101];
    int f = 0;
    int r = 0;

public:
    Queue(int size)
    {
        this->size = size;
    }
    bool Enqueue(int data)
    {
        if ((r + 1) % this->size == f)
            return false;
        r = (r + 1) % this->size;
        this->arr[r] = data;
        return true;
    }
    int Dequeue()
    {
        if (f == r)
            return -1;
        f = (f + 1) % this->size;
        return arr[f];
    }
    void Display()
    {
        if (f == r)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = (f + 1) % this->size;
        while (true)
        {
            if (i == (r + 1) % this->size)
                break;
            else
            {
                cout << " " << this->arr[i];
                i = (i + 1) % this->size;
            }
        }
        cout << endl;
    }
};