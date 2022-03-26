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

void levelOrder(node* root){

    if(root == NULL) return;

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *p = q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
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
    

    levelOrder(root);
    
}