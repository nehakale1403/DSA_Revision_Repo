#include<bits/stdc++.h>
using namespace std;


int maxSum(int arr[], int n){

    int dp[n];
    memset(dp, 0, sizeof(dp));
    int overall_max = 0;

    dp[0] = arr[0];
    for(int i=1; i<n; i++){
        int max_sum = arr[i];
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                
                max_sum = max(max_sum, arr[i] + dp[j]);
            }
        }
        dp[i] = max_sum;
        overall_max = max(overall_max, dp[i]);
    }
    return overall_max;

}

int main(){
    
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maxSum(arr, n);
}