#include<iostream>
#include<stack>
using namespace std;

bool removeRedundant(string &str){
    stack<char>st;
    for (int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            st.push(ch);
        }
        else if(ch == ')'){
            int operatorCount = 0;
            while(!st.empty() && st.top() != '('){
                
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    operatorCount++;
                }
                st.pop();
            }
            st.pop();

            if(operatorCount == 0){
                return true;
            }
        }
    }

    //agar yaha tak aa gaye hain to 
    //jarur do bracket ke bich main ek to operator mila hoga
    return false;
}

int main(){

    string str = "(((a+b)*(c+d)))";

    bool ans = removeRedundant(str);

    if(ans){
        cout<<"Redundant bracket present"<<endl;
    }
    else{
        cout<<"Redundant bracket not present"<<endl;
    }


    return 0;
}