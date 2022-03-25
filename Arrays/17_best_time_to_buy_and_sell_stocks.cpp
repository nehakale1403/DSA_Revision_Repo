#include<bits/stdc++.h>
using namespace std;

int maxProfit(int *arr, int n){
    int max_profit = 0;
    int mintillnow = arr[0];
    for(int i=1; i<n; i++){
        mintillnow = min(mintillnow, arr[i]);
        max_profit = max(max_profit, arr[i]-mintillnow);
    }
    return max_profit;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxProfit(arr, n);
}