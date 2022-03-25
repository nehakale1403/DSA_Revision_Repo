#include<bits/stdc++.h>
using namespace std;


int lis(int arr[], int n){

    int dp[n];
    memset(dp, 0, sizeof(dp));
    int final_max;
    dp[0] = 1;
    for(int i=1; i<n; i++){
        int maxfrombehind=0;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                maxfrombehind = max(maxfrombehind, dp[j]);
            }
        }
        dp[i] = maxfrombehind + 1;
        final_max = max(final_max, dp[i]);
    }
    return final_max;
}

int main(){
    
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<lis(arr, n);
}