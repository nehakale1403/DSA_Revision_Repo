#include<bits/stdc++.h>
using namespace std;


void sort(int *arr, int n){

    int i = 0, j = n-1;

    while(i<=j){
        while(arr[i] < 0)
            i++;
        while(arr[j]>0)
            j--;
        if(i<j)
            swap(arr[i++], arr[j--]);
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


// 6  
// -1 -2 4 5 6 -9