#include<bits/stdc++.h>
using namespace std;

int minJumpsDp(int *arr, int n){

    int dp[n];
    for(int i=0; i<n; i++)
        dp[i] = 1e8;

    dp[n-1] = 0;

    for(int i=n-2; i>=0; i--){
        if(arr[i] >= n-i){
            dp[i] = 1;
            continue;
        }else{
            int minval = 1e8;
            int loop=arr[i];
            int j=i+1;
            while(loop>0){
                minval = min(minval, dp[j]);
                j++;
                loop--;
            }
            dp[i] = minval+1;
        }
    }
    if(dp[0] >= 1e8){
        return -1;
    }
    return dp[0];
}

int minJumpsRecursive(int *arr,int idx, int n){

    if(arr[0] == 0) return -1;
    if(n == 1) return 0;
    if(idx >= n) return 0;
    if(arr[idx] > n-idx) return 1;

    int ans=INT_MAX;
    for(int i=1; i<=arr[idx]; i++){
        ans = min(ans, 1+ minJumpsRecursive(arr, idx+i, n));
    }
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    // cout<<minJumpsRecursive(arr,0, n)<<endl;
    cout<<minJumpsDp(arr, n);
}