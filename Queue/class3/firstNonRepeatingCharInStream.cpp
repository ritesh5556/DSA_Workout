#include<iostream>
#include<queue>
using namespace std;


int main(){
    string str = "ababc";
    queue<int> q;

    int freq[26] = {0};

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        //ans find karlo
        while(!q.empty()){
            char frontChar = q.front();

            if(freq[frontChar - 'a'] > 1){
                //yani  y ans nahi h
                q.pop();

            }
            else{
                //== 1 wala case
                //yehi ans hai
                cout<<frontChar<<"->";
                break;
            }
        }

        if(q.empty()){
            cout<<"#->";
        }
    }


    return 0;
}