#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
#include "BST.h"

using namespace std;

int main()
{
    int arr[100];
    Queue q(101);
    Linked_List ll(100);
    BST bst;

    for (int i = 0; i < 100; i++)
        arr[i] = 101 + i;

    for (int i = 0; i < 100; i++)
    {
        bool enqueued = q.Enqueue(arr[i]);
        if (!enqueued)
            cout << arr[i] << " couldn't be enqueued.\n";
    }
    cout << " The queue is below:\n";
    q.Display();
    cout << endl << endl;

    for (int i = 0; i < 100; i++)
    {
        int data = q.Dequeue();
        if (!(data % 2))
        {
            Node *tmp = new Node();
            tmp->data = data;
            ll.Insert(tmp);
        }
    }
    cout << " The linked list is below:\n";
    ll.Display();
    cout << endl;

    Node *header = ll.getHead();

    while (header != NULL)
    {
        bst.Insert(header->data);
        header = header->next;
    }
    cout << " The Binary Search Tree is below:\n";
    bst.Display();
    cout << endl;
    return 0;
}
