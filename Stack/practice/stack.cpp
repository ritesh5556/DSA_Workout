#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top = -1;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        
    }

    void push(int data){
        if(top == size-1){
            cout<<"Stack is overflow "<<endl;
            return;
        }
        else 
        {
            top++;
            arr[top] = data;
        }
        
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is underflow "<<endl;
            return;
        }
        else{
            top--;
        }
    }

    int getSize(){
        if(top == -1){
            return 0;
        }
        else{
            return top+1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            // cout<<"Stack is empty"<<endl;
            return true;
        }
        else{
            // cout<<"stack is not empty "<<endl;
            return false;
        }
    }

    int getTop(){
        if(top == -1){
            cout<<"Stack is empty";
            return 0;
        }
        else{
            return arr[top];
        }
    }

};

int main(){

    int n = 5;

    Stack st(n);

    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);

    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();

    // st.push(60);

    cout<<"size "<<st.getSize()<<endl;
    // Empty();
    cout<<"isEmpty : "<<st.isEmpty()<<endl;

    

    cout<<st.getTop()<<endl;



    return 0;
}