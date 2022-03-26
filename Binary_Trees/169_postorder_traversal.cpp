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

void postOrderRecursive(node* root){

    if(root == NULL)
        return;
     
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout<<root->data<<" "; 

}

void postOrderIterative(node *root){

    if(root == NULL)    
        return;
    
    stack<node*> st;
    stack<int> res;
    st.push(root);

    while(!st.empty()){
        node *p = st.top();
        st.pop();
        res.push(p->data);

        if(p->left) st.push(p->left);
        if(p->right) st.push(p->right);
    }

    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
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
    

    postOrderRecursive(root);
    cout<<endl;
    postOrderIterative(root);
    
}