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

void preorder(node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

node* build(){
    int d;cin>>d;
    if(d==-1) return NULL;
    node* n= new node(d);
    n->left=build();
    n->right=build();
    return n;
}

class Pair{
    public:
        int inc;
        int exc;
};

Pair max_subset(node* root){
    Pair p;
    if(!root){
        p.inc=0;
        p.exc=0;
        return p;
    }
    Pair left=max_subset(root->left);
    Pair right=max_subset(root->right);
    p.exc=max(left.exc,left.inc)+max(right.inc,right.exc);
    p.inc=root->data+left.exc+right.exc;
    return p;
}

int main(){
    node* root=build();
    Pair ans=max_subset(root);
    cout<<(ans.inc,ans.exc)<<endl;
    return 0;
}