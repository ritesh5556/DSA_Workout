#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerEle(int *arr, int size, vector<int> &ans){
    stack<int> st;
    st.push(-1);

    for(int i= size-1; i>=0; i--){
        int curr = arr[i];
        while( st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();

        st.push(curr);
    }
    return ans;
}

vector<int> prevSmallerEle(int *arr, int size, vector<int> &ans){
    stack<int> st;
    st.push(-1);

    for(int i= 0; i<size; i++){
        int curr = arr[i];
        while( st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();

        st.push(curr);
    }
    return ans;
}

int main(){
    int arr[5] = {8, 4, 6, 2, 3};
    int size = 5;

    vector<int> ans(size);

    ans = nextSmallerEle(arr, size, ans);
    cout<<"next : "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;


     vector<int> prev(size);

     prev = prevSmallerEle(arr, size, prev);
     cout<<"prev : "<<endl;
     for(auto i: prev){
        cout<<i<<" ";
     }
     cout<<endl;



    return 0;
}