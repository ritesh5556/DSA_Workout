#include <bits/stdc++.h>
using namespace std;

void solve(int ind, string str, vector<string> &ans){
    if(ind >= str.size()){
        ans.push_back(str);
    }

    for(int i= ind; i<str.size(); i++){
        swap(str[i], str[ind]);
        solve(ind+1, str, ans);
        // swap(str[i], str[ind]);
    }
}

int main(){

    string str = "abc";
    int ind = 0;
    vector<string> ans;
    solve(ind, str, ans);

    for(auto it : ans){
        cout<<it<<" ";
    }

    
    cout<<endl;

    return 0;
}