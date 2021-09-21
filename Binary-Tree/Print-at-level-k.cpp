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

void printatlevelkiter(node *root,int k){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    while(!q.empty()){
        if(level==k){
            while(q.front()!=NULL){
                cout<<q.front()->data<<" ";
                q.pop();
            }
            return;
        }
        else{
            node* t=q.front();q.pop();
            if(!t){
                level++;
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
    }
}

void printatlevelkrec(node* root,int k){
    if(!root) return;
    if(!k) cout<<root->data<<" ";
    printatlevelkrec(root->left,k-1);
    printatlevelkrec(root->right,k-1);
}

int main(){
    node* root=build();
    printatlevelkrec(root,2);
    return 0;
}