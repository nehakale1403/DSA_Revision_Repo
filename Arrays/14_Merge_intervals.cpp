#include<bits/stdc++.h>
using namespace std;

void mergeIntervals(vector<vector<int>> v, int n){

    sort(v.begin(), v.end());

    vector<pair<int, int>> res;

    stack<pair<int, int>> s;
    s.push({v[0][0], v[0][1]});

    for(int i=1; i<n; i++){
        cout<<"here"<<endl;
        if(s.top().second >= v[i][0]){
            pair<int, int> p = {s.top().first, max(v[i][1], s.top().second)};
            s.pop();
            s.push(p);
        }else{
            s.push({v[i][0], v[i][1]});
        }
    }

    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }

    reverse(res.begin(), res.end());

    for(int i=0; i<res.size(); i++)
        cout<<res[i].first<<"-"<<res[i].second<<" ";
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int> (2));
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        v[i][0] = x;
        v[i][1] = y;
    }

    mergeIntervals(v, n);

}