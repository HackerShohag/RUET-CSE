//Moudle 9 Topic 1
#include<bits/stdc++.h>

using namespace std;

class leafNode
{
public:
    int data;
    leafNode* LL;
    leafNode* RL;
};

class BST
{
public:
    leafNode* h = NULL;
public:
    void Insert(int x)
    {
        leafNode* temp = new leafNode();
        leafNode* i;
        temp->data = x;
        temp->LL = NULL;
        temp->RL = NULL;
        if (h == NULL) {
            h = temp;
        }
        else
        {
            i = h;
            while (1)
            {
                if (i->data >= x)
                {
                    if (i->LL == NULL)
                    {
                        i->LL = temp;
                        break;
                    }
                    else
                    {
                        i = i->LL;
                    }
                }
                else
                {
                    if (i->RL == NULL)
                    {
                        i->RL = temp;
                        break;
                    }
                    else
                    {
                        i = i->RL;
                    }
                }
            }
        }
    }

    void Display()
    {
        stack<leafNode *> st;
        leafNode *i = h;
        cout << "Node "<< "Node address "<< "L child "<< "Right child " << endl;
        if (i == NULL)
cout << "Tree is Empty" << endl;
        while (i != NULL || st.empty() != true)
        {
            if (i != NULL)
            {
                st.push(i);
                i = i->LL;
            }
            else
            {
                i = st.top();

                cout << i->data << " " << i << " " << i->LL << " " << i->RL << endl;
                st.pop();
                i = i->RL;
            }
        }
        cout << endl;
    }
};