#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int data){
        if(rear == size-1){
            cout<<"q is overflowed "<<endl;
            return ;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        if(front == -1 && rear == -1){
            cout<<"q is underflow "<<endl;
            return ;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            
        }
        else{
            arr[front]= -1;
            front++;
        }
    }

    int getFront(){
        if(front == -1){
            cout<<"q is empty "<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getSize(){
        if(front == -1){
            return 0;
        }
        else{
            return rear-front+1;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;

        }
        else{
            return false;

        }
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};

int main(){

    Queue q(5);
    q.push(10);
    q.print();
    q.push(20);
    q.print();

q.push(30);
    q.print();
q.push(40);
    q.print();
q.push(50);
    q.print();

    q.pop();
        q.pop();
    q.pop();
        q.pop();
    q.pop();



    q.print();

    // q.push(100);

    if(q.isEmpty()){
        cout<<"q is empyt or not : "<<q.isEmpty()<<endl;
    }
    else{
        cout<<"q is empyt or not : "<<q.isEmpty()<<endl;
    }


    cout<<"Front element : "<<q.getFront()<<endl;

    cout<<"Size of q : "<<q.getSize()<<endl;


    return 0;
}