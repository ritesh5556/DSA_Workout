#include <bits/stdc++.h>

using namespace std;

void solve(vector<string> &ans, string temp, int openCnt, int closeCnt, int n){

    if(temp.size() >= 2*n){
        ans.push_back(temp);
        return;
    }

    if(openCnt < n){
        solve(ans, temp + "(", openCnt +1, closeCnt, n);
    }
    
    if(closeCnt < openCnt){
        solve(ans, temp + ")", openCnt, closeCnt + 1, n);
    }
    
}


int main(){

    int n = 2;

    vector<string> ans; 

    solve(ans, "", 0, 0, n);

    for(auto it: ans){
        cout<<it<<endl;
    }


    return 0;
}