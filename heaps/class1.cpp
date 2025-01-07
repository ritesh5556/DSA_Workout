#include <bits/stdc++.h>

using namespace std;

class Heap{
    public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity){
        this->arr= new int[capacity];
        this->capacity = capacity;
        size = 0;

    }

    void insert(int val){
        if(size > capacity){
            cout<<"Overflow"<<endl;
            return;
        }

        size++;
        int index = size;

        arr[index] = val;

        while(index > 1){
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);

                index = parentIndex;
            }
            else break;
        }

        
    }

    int deleteHeap(){
        if(size == 0){
            cout<<"Heap underflow";
            return -1;
        }

        
        int temp = arr[1];
        arr[1] = arr[size];
        

        size--;

        int index = 1;

        while(index <= size){
            int largestInd = index;
            
            int leftInd = index*2;
            int rightInd = index*2 + 1;

        
            
            if( arr[leftInd] > arr[largestInd]){
               
                largestInd = leftInd;
                
            }

            if(arr[rightInd] > arr[largestInd]){
            
                largestInd = rightInd;
            }

            

            if(largestInd == index){
                
                break;
            }
           
            
                
                swap(arr[index], arr[largestInd]);
                index = largestInd;
            

            
        }
        return temp;
    
    }

    void printHeadp(){
        for(int i=1; i<= size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};

void heapify(int *arr, int n, int index){
    int leftInd = index*2;
    int rightInd = index*2+1;
    int largestInd = index;

    if(leftInd <= n && arr[leftInd] > arr[largestInd]){
        largestInd = leftInd;
    }

    if(rightInd <= n && arr[rightInd] > arr[largestInd]){
        largestInd = rightInd;
    }

    if(index != largestInd){
        swap(arr[index], arr[largestInd]);

        index = largestInd;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n){
    
    for(int index = n/2; index> 0; index--){
        heapify(arr, n, index);
    }
}

void sortHeap(int *arr, int n){
    
    while(n != 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main(){

    int arr[] = {-1, 5, 10, 15, 20, 25, 12 };
    int n = 6;

    buildHeap(arr, n);

    for(int i=1; i<= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"After heap sort"<<endl;

    sortHeap(arr, n);

    for(int i=1; i<= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    // Heap *h = new Heap(10);

    // h->insert(10);
    // h->insert(5);
    // h->insert(15);
    // h->insert(20);
    // h->insert(6);


    // cout<<"Print Heap"<<endl;
    // h->printHeadp();

    // cout<<"Deleted : "<< h->deleteHeap()<<endl;

    // cout<<"After delete"<<endl;
    // h->printHeadp();

    // cout<<"Deleted : "<< h->deleteHeap()<<endl;

    // cout<<"After delete"<<endl;
    // h->printHeadp();


    return 0;
}