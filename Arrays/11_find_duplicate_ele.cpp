#include<bits/stdc++.h>
using namespace std;

int findDup(int *arr, int n){

    while(true){
        if(arr[0] != arr[arr[0]]){
            swap(arr[0], arr[arr[0]]);
        }else{
            return arr[0];
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<findDup(arr, n);
}