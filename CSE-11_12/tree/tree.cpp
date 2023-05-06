#include <bits/stdc++.h>
#include "node.h"

using namespace std;

class tree
{
private:
    node *header;
    node *current;
    int size = 0;

public:
    tree()
    {
        this->header->data = data;
        this->current = this->header;
        size++;
    };
    void addNode(node *Node, bool direction)
    {
        if (direction == 0)
            header->left = Node;
        else
            header->right = Node;
        current = Node;
        size++;
    }
    void printTree()
    {
        for (size_t i = 0; i < this->size; i++)
        {
            /* code */
        }
    }
    ~tree();
};

int main()
{
    tree t;
    t.addNode(new node(20), 0);
}