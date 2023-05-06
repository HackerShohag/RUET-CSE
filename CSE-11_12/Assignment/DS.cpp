#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

struct Data {
    int left;
    int data;
    int right;
};

class tree {
    private:
        Node *root;

    public:
        tree()
        {
            root = NULL;
        }
        void readTree(string fileName)
        {
            vector<Node*> addresses;
            vector<Data> vect;
            Data temp;
            ifstream in(fileName);
            while (in >> temp.left >> temp.data >> temp.right)
            {
                vect.push_back(temp);
            }
            addresses.push_back(NULL);
            for (int i = 0; i < vect.size(); i++)
            {
                Node *node = new Node();
                addresses.push_back(node);
            }
            for (int i = 1; i <= vect.size(); i++)
            {
                addresses[i]->data = vect[i - 1].data;
                addresses[i]->left = addresses[vect[i - 1].left];
                addresses[i]->right = addresses[vect[i - 1].right];
            }
            root = addresses[1];
        }
        int InOrderTravese()
        {
            stack<Node *> s;
            Node *curr = root;
            int sum = 0;
            while (curr != NULL || s.empty() == false)
            {
                while (curr != NULL)
                {
                    if (!curr->left && !curr->right)
                    {
                        sum += curr->data;
                    }
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                cout << curr->data << endl;
                curr = curr->right;
            }
            return sum;
        }
        int sum()
        {
            return InOrderTravese();
        }
};

int main() {
    tree tr;
    tr.readTree("data.txt");
    tr.InOrderTravese();
    cout << tr.sum() << endl;
    return 0;
}
