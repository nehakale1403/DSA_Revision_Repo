#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(int arr1[], int arr2[], int m, int n){

    set<int> s;
    vector<int> res;
    for(int i=0; i<m; i++){
        s.insert(arr1[i]);
    }

    for(int i=0; i<n; i++){
        if(s.find(arr2[i]) != s.end()){
            res.push_back(arr2[i]); 
        }  
    }
    return res;
}

set<int> unionOfArr(int arr1[], int arr2[], int m, int n){

    set<int> s;
    for(int i=0; i<m; i++){
        s.insert(arr1[i]);
    }
    for(int i=0; i<n; i++){
        s.insert(arr2[i]);
    }
    return s;
}

int main(){
    int m, n;
    cin>>m>>n;

    int arr1[m];
    for(int i=0; i<m; i++) cin>>arr1[i];

    int arr2[n];
    for(int i=0; i<n; i++) cin>>arr2[i];

    set<int> uni_res = unionOfArr(arr1, arr2, m, n);
    vector<int> intr_res = intersection(arr1, arr2, m, n);
    for(auto it:uni_res) cout<<it<<" ";
    cout<<endl;
    for(auto it:intr_res) cout<<it<<" ";

}