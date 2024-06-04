#include <iostream>
#include <stack>
using namespace std;

void insertInSorted(stack<int> &st, int val)
{
    // base case;
    if (st.empty())
    {
        st.push(val);
        return;
    }
    if (val > st.top())
    {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();

    insertInSorted(st, val);
    st.push(temp);
}

int main()
{

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    insertInSorted(st, 25);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}