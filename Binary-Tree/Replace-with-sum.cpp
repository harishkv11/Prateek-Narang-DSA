#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
};

node* build(){
    int d;cin>>d;
    if(d==-1) return NULL;
    node* n= new node(d);
    n->left=build();
    n->right=build();
    return n;
}

void preorder(node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int replace_with_sum(node* &root){
    if(!root) return 0;
    if(!root->left and !root->right){
        return root->data;
    }
    int old=root->data;
    int left=replace_with_sum(root->left);
    int right=replace_with_sum(root->right);
    root->data=left+right;
    return root->data+old;
}
int main(){
    node* root=build();
    preorder(root);cout<<endl;
    replace_with_sum(root);
    preorder(root);
    return 0;
}