#include<bits/stdc++.h>
using namespace std;

int minimizeMaxDiff(int *arr, int n, int k){
    
    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;

    int ans= arr[n-1] - arr[0]; 

    int minimum, maximum;
    for(int i=0; i<n; i++){
        minimum = min(smallest, arr[i+1]-k);
        maximum = max(largest, arr[i]+k);
        
        if(minimum > 0)
            ans = min(ans, maximum-minimum);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    cout<<minimizeMaxDiff(arr, n, k);

}
