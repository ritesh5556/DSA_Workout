#include<iostream>
using namespace std;

int findEle(int row, int col){
        if(row == 0 || col == 0){
            return 1;
        }
        
        int ans = 1;
        for(int i = 1; i<= col; i++){
            ans =  ans * row;
            ans = ans / i;
            row--;
        }

        return ans;
    }

int main(){

    cout<<findEle(4, 4);

    return 0;
}