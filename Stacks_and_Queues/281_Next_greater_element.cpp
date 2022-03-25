#include<bits/stdc++.h>
using namespace std;

void printNextGreatestEle(int arr[], int n){
    
    stack<int> st;
    stack<int> res;

    for(int i=n-1; i>=0; i--){
        if(st.empty()){
           res.push(-1);
        }else{
            while(!st.empty() && st.top() < arr[i])
                st.pop();
            if(st.top() > arr[i]){
                res.push(st.top());
            }else{
                res.push(-1);
            }

        }
        st.push(arr[i]);
    }

    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
        
    
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    printNextGreatestEle(arr, n);
}