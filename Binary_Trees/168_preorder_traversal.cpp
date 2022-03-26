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

void preOrderRecursive(node* root){

    if(root == NULL)
        return;
    
    cout<<root->data<<" "; 
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);

}

void preOrderIterative(node *root){

    if(root == NULL)    
        return;
    
    stack<node*> st;

    node* p = root;
    st.push(root);
    while(!st.empty()){
        p = st.top();
        st.pop();
        cout<<p->data<<" ";

        if(p->right) st.push(p->right);
        if(p->left) st.push(p->left);
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
    

    preOrderRecursive(root);
    cout<<endl;
    preOrderIterative(root);
    
}