#include<iostream>
#include<stack>
using namespace std;

bool removeRedundant(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '*' || ch == '-' || ch == '+' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            int operatorCount  = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    
                    operatorCount++;
                }
                st.pop();
            }
            //yaha pr aap tabhi pohochoge jab 
            //aapke stack ke top pr ek opening bracket hogo
            st.pop();
          
            if(operatorCount == 0){
                return true;
            }

        }
    }
    //agaar main yaha tak pohancha hu 
    // iska matlab ke har ek bracket k pair k bich main
    //ek operator pakka mila hain
    return false;
}

int main(){
    string s = "(((a+b) * (a+b)))";
    bool ans = removeRedundant(s);

    if(ans){
        cout<<"Redudant bracket present"<<endl;
    }
    else{
        cout<<"Redudant bracket absent"<<endl;
    }

    return 0;
}