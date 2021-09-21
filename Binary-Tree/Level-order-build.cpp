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


node* levelorderbuild(){
    int d;cin>>d;
    node* root=new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* t=q.front();q.pop();
        int l,r;cin>>l>>r;
        if(l!=-1){
            t->left=new node(l);
            q.push(t->left);
        }
        if(r!=-1){
            t->right=new node(r);
            q.push(t->right);
        }
    }
    return root;
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
    node* root=levelorderbuild();
    levelbylevel(root);
    return 0;
}