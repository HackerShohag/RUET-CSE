#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

int sumLeafValues(Node *h) {
    if (h == nullptr)
        return 0;
    int total = 0;
    if (h->left == nullptr && h->right == nullptr)
    {
        total += h->value;
    }
    else
    {
        total += sumLeafValues(h->left);
        total += sumLeafValues(h->right);
    }
    return total;
}

int main() {
    Node *root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};
    root->left->left->left = new Node{8, nullptr, nullptr};
    root->left->left->right = new Node{9, nullptr, nullptr};
    root->left->right->left = new Node{10, nullptr, nullptr};
    root->left->right->right = new Node{11, nullptr, nullptr};
    int total = sumLeafValues(root);
    cout << "Total: " << total << endl;
    return 0;
}