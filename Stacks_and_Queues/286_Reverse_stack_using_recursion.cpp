#include<bits/stdc++.h>
using namespace std;

stack<int> insertAtBottomRecursive(stack<int> &st,int n){
    
    if(st.empty()){
        st.push(n);
    }else{
        int ele = st.top();
        st.pop();
        insertAtBottomRecursive(st, n);
        st.push(ele);
    }

    return st;
}

void reverseStack(stack<int> &st){

    if(st.empty())
        return;

    int ele = st.top();
    st.pop();
    reverseStack(st);
    
    insertAtBottomRecursive(st, ele);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    reverseStack(st);

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}