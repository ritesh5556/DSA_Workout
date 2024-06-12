#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseFirseK(queue<int> &q, int k){
    stack<int> st;
    int n = q.size();

    if(k>n || n==0){
        return;
    }

    //push first k elements into stack
    for(int i=0; i<k; i++){
        int element = q.front();
        q.pop();
        st.push(element);
    }

    //push all k elements into queue from stack
    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
    
    // pop ans push first (n-k) elements into queue again

    for(int i = 0; i<(n-k); i++){
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int  k = 3;

    reverseFirseK(q, k);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}