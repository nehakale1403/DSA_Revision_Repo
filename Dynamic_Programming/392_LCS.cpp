#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){

    int m = s1.length();
    int n = s2.length();

    if(m == 0 || n == 0)
        return 0;

    if(s1[0] == s2[0])
        return 1 + lcs(s1.substr(1), s2.substr(1));
    else
        return max(lcs(s1.substr(1), s2), lcs(s1, s2.substr(1)));

}

int main(){
    
    string s1, s2;

    cin>>s1>>s2;

    cout<<lcs(s1, s2);
}