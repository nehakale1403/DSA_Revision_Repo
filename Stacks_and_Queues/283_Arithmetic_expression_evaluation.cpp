#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '^')
        return 3;
    else if((c == '*') || c == '/')
        return 2;
    else if((c == '+') || (c == '-'))
        return 1;
    else
        return -1;
}



string infixToPostfix(string s){

    stack<char> st;
    string res = "";
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <='z')){
            res += ch;
        }else if(ch == '('){
            st.push('(');
        }else if(ch == ')'){
            while(st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && prec(st.top()) >= prec(ch)){
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }  
    while(!st.empty()){
        res += st.top(); 
        st.pop();
    }
        
    return res;

}

string infixToPrefix(string s){

    int l = s.size();
 
    // Reverse infix
    reverse(s.begin(), s.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (s[i] == '(') {
            s[i] = ')';
            i++;
        }
        else if (s[i] == ')') {
            s[i] = '(';
            i++;
        }
    }
 
    string prefix = infixToPostfix(s);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}

int main(){

    string s;
    cin>>s;

    cout<<infixToPostfix(s);
    cout<<infixToPrefix(s);
}