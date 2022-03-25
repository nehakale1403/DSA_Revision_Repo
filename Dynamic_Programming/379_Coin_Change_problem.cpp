#include<bits/stdc++.h>
using namespace std;

int countCoinChange(int *arr, int n, int target){

    if(target == 0)
        return 1;
    if(target < 0 || n < 0)
        return 0;

    return countCoinChange(arr, n, target-arr[n-1])+ countCoinChange(arr, n-1, target);
}

int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<countCoinChange(arr, n, k);
}