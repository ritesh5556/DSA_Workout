#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQ(queue<int> &q){
    stack<int>st;

    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

void reverse(queue<int> &q){
    // base case
    if(q.empty()){
        return ;
    }

    int  temp = q.front();
    q.pop();

    reverse(q);

    q.push(temp);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // reverseQ(q);

    reverse(q);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    
    
    


    return 0;
}