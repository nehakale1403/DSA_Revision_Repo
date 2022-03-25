#include<bits/stdc++.h>
using namespace std;

int lisUtil(int *arr,  int n, int *dp){

    if(dp[n] != -1)
        return dp[n];

    dp[n] = 1; //single element is also an lis

    for(int i = 0; i<n; i++){
        if(arr[n] > arr[i]){
            dp[n] = max(dp[n], 1 + lisUtil(arr, i, dp));
        }
    }

    return dp[n];
}

int lis(int arr[], int n){

    int dp[n];
    memset(dp, -1, sizeof(dp));
    return lisUtil(arr, n-1, dp);
}

int main(){
    
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<lis(arr, n);
}