#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    int n = s.length();

    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    return s;
}

string handleOdd(string s){
    int n = s.length();
    int mid = n/2;
    string left = s.substr(0, mid);
    string right = s.substr(mid+1);
    string smid = s.substr(mid, 1);
    string r_left = reverse(left);
    
    if(stoi(r_left) < stoi(right)){
        string mixed = left+smid;
        int num = stoi(mixed)+1;
        left = to_string(num);
        right = left;
    }
    return left + right;
}

string handleEven(string s){

    int n = s.length();
    int mid = n/2;
    string left = s.substr(0, mid);
    string right = s.substr(mid);
    
    string r_left = reverse(left);
    if(stoi(r_left) > stoi(right)){
        right = r_left; //done
    }else{
        int num = stoi(left)+1;
        left = to_string(num);
        right = reverse(left);
    }
    return left+right;
}

string nextSmallestPalindrome(string s){

    if(s.length() & 1)
        return handleOdd(s);
    else
        return handleEven(s);
}


int main(){
    string s;
    cin>>s;

    cout<<nextSmallestPalindrome(s);
}