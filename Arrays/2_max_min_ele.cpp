#include<bits/stdc++.h>
using namespace std;

pair<int, int> treeMethod(int arr[], int n){

    int maxele;
    int minele;

    int start;
    if(n%2==0){
        minele = min(arr[0], arr[1]);
        maxele = max(arr[0], arr[1]);
        start = 2;
    }else{
        minele = arr[0];
        maxele = arr[0];  
        start = 1;  
    }
    for(int i = start; i<n-1; i+=2){
        maxele = max({maxele, arr[i], arr[i+1]});
        minele = min({minele, arr[i], arr[i+1]});
    }
    
    return make_pair(minele, maxele);
    
}

pair<int, int> findMaxMin(int arr[], int n){
    
    int maxele = arr[0];
    int minele = arr[0];

    for(int i=1; i<n; i++){
        maxele = max(maxele, arr[i]);
        minele = min(minele, arr[i]);
    }
    return make_pair(minele, maxele);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    // pair<int, int> ans = findMaxMin(arr, n);
    

    pair<int, int> ans = treeMethod(arr, n);
    cout<<ans.first<<" "<<ans.second;
}