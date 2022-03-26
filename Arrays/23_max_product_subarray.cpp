#include<bits/stdc++.h>
using namespace std;

int maxProd(int *arr, int n){

    int maxtillnow = arr[0];
    int mintillnow = arr[0];
    int maxoverall = arr[0];

    for(int i=1; i<n; i++){
        int temp = maxtillnow;
        maxtillnow = max({maxtillnow * arr[i], mintillnow * arr[i], arr[i]});
        mintillnow = min({temp * arr[i], mintillnow * arr[i], arr[i]});
        maxoverall = max(maxoverall, maxtillnow);
    }
    return maxoverall;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    cout<<maxProd(arr, n);

}