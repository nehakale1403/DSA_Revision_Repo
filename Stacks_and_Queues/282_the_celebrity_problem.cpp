#include<bits/stdc++.h>
using namespace std;
#define n 3
int arr[n][n];
bool knows(int a, int b)
{
    return arr[a][b];
}

int main(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    stack<int> st;
    for(int i=0; i<n; i++)
        st.push(i);

    while(st.size() > 1){
        int person1 = st.top();
        st.pop();
        int person2 = st.top();
        st.pop();

        if(knows(person1, person2) && !knows(person2, person1)){
            st.push(person2);
        }else{
            st.push(person1);
        }
    }
    if(st.empty())
        cout<<-1;
    int celeb = st.top();

    for(int i=0; i<n; i++){
        if(i!=celeb && (knows(celeb, i) || !knows(i, celeb))){
            cout<<-1;
            return 0;
        }
    }
    cout<<celeb<<endl;
}