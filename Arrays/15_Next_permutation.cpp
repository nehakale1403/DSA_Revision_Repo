#include<bits/stdc++.h>
using namespace std;

void nextPermutation(int *arr, int n){
    int i = n-2;

    while(arr[i] >= arr[i+1] && i>=0)
        i--;
    
    int j = n-1;
    while(j>i){
        if(arr[j] > arr[i]){
            break;
        }else{
            j--;
        }
    }

    swap(arr[i], arr[j]);

    reverse(arr+i+1, arr+n);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    nextPermutation(arr, n);

    for(int i=0; i<n; i++)
        cout<<arr[i];
}