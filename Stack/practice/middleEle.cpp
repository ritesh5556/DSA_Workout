#include <iostream>
#include <stack>

using namespace std;



int middleEle(stack<int>st, int &pos){
    
    
    if(pos == 1){
        return st.top();
    }

    int temp = st.top();
    st.pop();
    pos--;
    int ans = middleEle(st, pos);
    st.push(temp);
    return ans;
    
}

int  main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // st.push(50);

    if(st.empty()){
        cout<<"Stack is empty "<<endl;
        return 0;
    }

    int  size = st.size();
    int pos ;
    if(size &1){
        pos = (size/2)+1;
    }
    else{
        pos =( size/2);
    }
    
    cout<<"Middle element is : "<<middleEle(st, pos)<<endl;


    return 0;

}