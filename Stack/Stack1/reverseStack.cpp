#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st, int val){
    //base case
    if(st.empty()){
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtBottom(st, val);
    st.push(temp);
}

//Reverse stack
void reverseStack(stack<int>&st){
    //base case
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}


int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int val = 400;
   

    // insertAtBottom(st, val);
    //     cout<<"after "<<endl;
    reverseStack(st);

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    

    return 0;
}