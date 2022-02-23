#include<bits/stdc++.h>
using namespace std;

void sort(int *arr, int n){

    int l = 0;
    int r = n-1;
    int m = 1;

    while(m<=r){
        if(arr[m] == 0){
            swap(arr[l++], arr[m++]);
        }else if(arr[m] == 2){
            swap(arr[m], arr[r--]);
        }else{
            m++;
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr, n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}