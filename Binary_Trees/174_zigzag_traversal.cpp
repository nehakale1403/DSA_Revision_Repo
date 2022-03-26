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

void zigzagTraversal(node* root){

    if(root == NULL)
        return;
    
    bool lefttoright=true;
    stack<node*> currLevel;
    stack<node*> nextLevel;
    currLevel.push(root);

    while(!currLevel.empty()){
        node* p = currLevel.top();
        currLevel.pop();
        cout<<p->data<<" ";
        if(lefttoright){
            if(p->left) nextLevel.push(p->left);
            if(p->right) nextLevel.push(p->right);
        }else{  
            if(p->right) nextLevel.push(p->right);
            if(p->left) nextLevel.push(p->left);
        }

        if(currLevel.empty()){
            lefttoright = !lefttoright;
            swap(currLevel, nextLevel);
        }
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
    

    zigzagTraversal(root);
    
}