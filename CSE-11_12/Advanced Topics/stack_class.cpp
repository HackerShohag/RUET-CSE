#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> st;
    st.push(21);
    st.push(31);
    st.pop();
    cout << "Top element: " << st.top() << endl;

    if (st.empty())
        cout << "The stack is empty.\n";
    else
        cout << "The stack is not empty.\n";
}