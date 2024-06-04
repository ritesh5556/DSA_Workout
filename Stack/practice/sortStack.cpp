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

void sortStack(stack<int>&st){

    //base condition
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();

    sortStack(st);
    insertInSorted(st,temp);
}

int main()
{

    stack<int> st;

    st.push(20);
    st.push(40);
    st.push(30);
    st.push(10);
    st.push(50);

    
    sortStack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}