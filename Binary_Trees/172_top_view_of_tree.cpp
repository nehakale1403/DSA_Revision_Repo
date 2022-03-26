#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void topView(node *root){

    if(root == NULL)    
        return;
    
    map<int, int> mp;
    queue<pair<node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        node *p = q.front().first;
        int idx = q.front().second;
        q.pop();

        if(mp.find(idx) == mp.end()){
            mp[idx] = p->data;
        }
        if(p->left) q.push({p->left, idx-1});
        if(p->right) q.push({p->right, idx+1});
    }

    for(auto it: mp){
        cout<<it.second<<" ";
    }
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    

    topView(root);
    
}