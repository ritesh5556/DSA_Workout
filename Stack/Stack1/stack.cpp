#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top = -1;
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "stack is overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is underflow " << endl;
        }
        else
        {
            top--;
        }
    }

    int getSize()
    {
        return top + 1;
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "stack is empty " << endl;
            return -1;
        }
        else
        {

            return arr[top];
        }
    }
};

void solve(Stack &st, int& pos , int &ans){
    // base case
    if (pos == 1)
    {
        ans =  st.getTop();
        return;
    }

    int temp = st.getTop();
    st.pop();
    pos--;    
    solve(st, pos, ans);
    st.push(temp);
}

int middleEle(Stack st)
{
    if(st.empty()){
        cout<<"stack is empty "<<endl;
        return -1;
    }
       int pos;
    int len = st.getSize();
    if (len & 1)
    {
        pos = len / 2 + 1;
    }
    else
    {
        pos = len / 2;
    }
    int ans = -1;
    solve(st, pos , ans);
    return ans;
    
}

int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
   
    
   cout<< middleEle(st)<<endl;

    // while (!st.empty())
    // {
    //     cout << st.getTop() << " ";
    //     st.pop();
    // }

    return 0;
}