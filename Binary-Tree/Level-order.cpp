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

void level(node* root){
    if(!root) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* t=q.front();q.pop();
        cout<<t->data<<" ";
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
    cout<<endl;
}

void levelbylevel(node* root){
    if(!root) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* t=q.front();q.pop();
        if(!t){
            if(!q.empty()) q.push(NULL);
            cout<<endl;
        }
        else{
            cout<<t->data<<" ";
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
        }
    }
}


int main(){
    node* root=build();
    level(root);
    levelbylevel(root);
    return 0;
}