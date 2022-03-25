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

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    int n;
    cin>>n;

    stack<int> ans = insertAtBottomRecursive(st, n);

    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
}