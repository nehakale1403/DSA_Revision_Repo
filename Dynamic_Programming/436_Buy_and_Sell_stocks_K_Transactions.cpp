#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n, int k){

    vector<vector<int>> dp(k+1, vector<int>(n, 0));

    for(int i=1; i<k+1; i++){
        for(int j=0; j<n; j++){
            int maxx = INT_MIN;
            for(int p=0; p<j; p++)
                maxx = max(maxx, dp[i-1][p] + arr[j]- arr[p]);
            if(j!=0){
                maxx = max(maxx, dp[i][j-1]);
                dp[i][j] = maxx;
            }
                
        }
    }
    return dp[k][n-1];
}

int maxProfitOptimized(int arr[], int n, int k){

    vector<vector<int>> dp(k+1, vector<int>(n, 0));

    for(int i=1; i<=k; i++){
        int maxx = INT_MIN;
        for(int j=1; j<n; j++){
            maxx = max(maxx, dp[i-1][j-1]-arr[j-1]);

            dp[i][j] = max(maxx + arr[j], dp[i][j-1]);
                
        }
    }
    return dp[k][n-1];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    cout<<maxProfit(arr, n, k);
    cout<<maxProfitOptimized(arr, n, k);
}