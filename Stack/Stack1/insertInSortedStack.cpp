#include<iostream>
#include<stack>
using namespace std;

//Insert In Sorted Array
void insertInSorted(stack<int> &st, int val){
    //base case
    if(st.empty()){
        st.push(val);
        return;
    }
    if(val > st.top()){
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();

    insertInSorted(st, val);
    st.push(temp);


}

void sortStack(stack<int>&st){
    //base case
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();
    sortStack(st);
    insertInSorted(st, temp);
}

int main(){
    stack<int>st;
    st.push(20);
    st.push(10);
    
    st.push(30);
    
    st.push(50);
    st.push(40);
    int val = 5;
   
    sortStack(st);
//    insertInSorted(st, val);

    while (!st.empty())
    {
        cout<<st.top()<<" "<<endl;
        st.pop();
    }
    

    return 0;
}