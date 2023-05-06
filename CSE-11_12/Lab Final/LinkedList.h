#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Linked_List {
    private:
        int size = 0;
        Node* header;
        Node* q = NULL;
        Node* tmp = NULL;

    public:
        Linked_List(int size) {
            header = NULL;
            this->size = size;
        }
        void Insert(Node* node) {
            for (int i = 0; i < size; i++) {
                if (this->header == NULL) this->header = node;
                else if (this->q != NULL) this->q->next = node;
                this->q = node;
            }
            this->q->next = NULL;
        }

        void Display()
        {
            Node* i = this->header;
            while (i != NULL)
            {
                cout << i->data << " ";
                i = i->next;
            }
            cout << endl;
        }
        Node* getHead() {
            return this->header;
        }
};