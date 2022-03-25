#include<bits/stdc++.h>
using namespace std;

int findMid(stack<int> st, int n, int curr){


    if(st.empty() || curr==n)
        return -1;

    if(curr == n/2)
        return st.top();
    
    int ele = st.top();
    st.pop();
    return findMid(st, n, curr+1);

}

int main(){
    
    stack<int> st;
    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        st.push(x);
    }

    cout<<findMid(st, n, 0);
}