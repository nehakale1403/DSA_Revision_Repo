#include<bits/stdc++.h>
using namespace std;


int main(){
    
    stack<int> st;
    int n;
    cin>>n;

    int minele=INT_MAX;

    stack<int> special_st;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        minele = min(minele, x); 
        st.push(x);
        special_st.push(minele);
    }

    cout<<special_st.top();
}