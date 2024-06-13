#include<iostream>
#include<deque>
using namespace std;

void removeFirstNeg(int *arr, int n, int k){
    deque<int> dq;
    //process first k elements - first window
    for(int index = 0; index < k; index++){
        if(arr[index] < 0){
            dq.push_back(index);
        }
    }

    //process remaining windows -> Removal an Addition
    for(int index=k; index<n; index++){
        //aage badhne se pahile purani window ka answer nikaldo
        cout<<arr[dq.front()]<<" ";

        //Removal - jo  bhi index out of range h, usko queue main se remove kardo
        if(index- dq.front() >= k){
            dq.pop_front();
        }

        //Addition
        if(arr[index] < 0){
            dq.push_back(index);
        }
    }

    //last window ka answer print kardo
    if(dq.empty()){
        cout<<"0"<<endl;
    }
    else{
        cout<<arr[dq.front()]<<endl;
    }
}

int main(){

    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int n = 7;
    int k = 3;

    removeFirstNeg(arr, n, k);


    return 0;
}