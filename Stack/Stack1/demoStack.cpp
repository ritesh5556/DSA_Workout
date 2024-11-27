#include<iostream>
using namespace std;

class Stack{
public:
    int *arr;
    int size;
    int top=-1;

    Stack(int size){

        arr = new int[size];
        this->size = size;
    }

    void push(int data){
        if(top == size-1){
            cout<<"stack is overflow "<<endl;
            return;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"stack is underflow "<<endl;
            return;
        }
        else{
            top--;
        }
    }

    int getSize(){
        if(top == -1){
            cout<<"stack is underflow"<<endl;
            return 0;
        }
        else{
            return top+1;
        }
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        if(top == -1){
            cout<<"stack is underflow "<<endl;
            return 0;
        }
        else{
            return arr[top];
        }
    }
};

int main(){

    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<"is empty : "<<st.empty()<<endl;
     st.pop();

    cout<<"top : "<<st.getTop()<<endl;
   
    

    while (!st.empty())
    {
        cout<<st.getTop()<<" ";
        st.pop();
    }
    


    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                   