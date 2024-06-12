#include<iostream>
using namespace std;

class Dqueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Dqueue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val){
        if((front == 0 && rear == size-1) || (front - rear == 1)){
            cout<<"overflow"<<endl;
            return ;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;

        }
    }

    void pushFront(int val){
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout<<"overflow"<<endl;
            return ;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = val;
        }
        else{
            front--;
            arr[front] = val;
        }
    }

    void popFront(){
        if(front == -1 && rear == -1){
            cout<<"underflow"<<endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front =0;

        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    void popBack(){
        if(front == -1 && rear == -1){
            cout<<"underflow"<<endl;
        }

        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        else if(rear == 0){
            arr[rear] = -1;
            rear = size-1;
        }
        else{
            arr[rear] = -1;
            rear--;
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
    Dqueue q(5);
    
    q.pushFront(20);
    q.pushFront(30);

    q.print();


    // q.pushBack(10);
    // q.print();
    // q.pushBack(30);
    // q.pushBack(40);
    // q.pushBack(50);
    //     q.pushBack(500);

    // q.popFront();
    // q.popBack();
    // q.popBack();
    // q.popBack();
    // q.popBack();
    // q.popBack();
    // q.popBack();

    q.print();


    


    return 0;
}