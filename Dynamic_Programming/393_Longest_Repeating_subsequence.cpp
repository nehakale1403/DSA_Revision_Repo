#include<bits/stdc++.h>
using namespace std;

int lrsUtil(string s, int i, int j, vector<vector<int>> &dp){

    if(i >= s.length() || j >= s.length())
        return 0;
    else if(dp[i][j] != -1)
        return dp[i][j];
    else if(s[i] == s[j] && i != j)
        return dp[i][j] = 1 + lrsUtil(s, i+1, j+1, dp);
    else
        return dp[i][j] =  max(lrsUtil(s, i+1, j, dp), lrsUtil(s, i, j+1, dp));
    
}

int lrs(string s){

    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    return lrsUtil(s, 0, 0, dp);
}

int main(){
    string s;
    cin>>s;

    cout<<lrs(s);
}