#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }

    int temp = st.top();

    st.pop();

    insertAtBottom(st, data);
    st.push(temp);
}

void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }

    int temp = st.top();

    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);

   


}

int main()
{

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    
    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}