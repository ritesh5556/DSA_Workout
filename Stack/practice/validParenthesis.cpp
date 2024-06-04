#include <iostream>
#include <stack>
using namespace std;

bool validParenthesis(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '['  || ch ==  '{')
        {
            st.push(ch);
        }
        else
        {
            // closing bracket hain
            if(!st.empty()){
                if (ch == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (ch == ']' && st.top() == '[')
            {
                st.pop();
            }
            else if (ch == '}' && st.top() == '{')
            {
                st.pop();
            }

            }
            else{
                return false;
            }
            
            
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{

    stack<char> st;
    string str = "({[]()})";


    if(validParenthesis(str)){
        cout<<"Valid Parenthesis "<<endl;
    }
    else{
        cout<<"Not Valid Parenthesis "<<endl;
    }

    return 0;
}