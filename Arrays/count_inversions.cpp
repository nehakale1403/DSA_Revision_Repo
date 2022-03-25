#include<bits/stdc++.h>
using namespace std;

int merge(int *arr, int l, int mid, int h){

    int inv_cnt = 0;

    int i=l, j = mid;
    while((i<=mid-1) && (j<=h)){
        
        if(arr[i] > arr[j]){
            inv_cnt += mid-i;
            j++;
        }else{
            i++;
        }
    }
    return inv_cnt;
}

int mergesort(int *arr, int l, int h){

    int inv = 0;

    if(l<h){
        int mid = (l+h)/2;
        inv += mergesort(arr, l, mid);
        inv += mergesort(arr, mid+1, h);
        inv += merge(arr, l, mid+1, h);
    }
    return inv;
}
int countInversions(int arr[], int n){
    return mergesort(arr, 0, n-1);
}
int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<countInversions(arr, n);

}