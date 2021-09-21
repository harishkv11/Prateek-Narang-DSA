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

int height(node *root){
    if(!root) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

int diameter(node* root){
    if(!root) return 0;
    int d1=diameter(root->left);
    int d2=diameter(root->right);
    int d3=height(root->left)+height(root->right);
    return max({d1,d2,d3});
}

//---------------
class HDpair{
    public:
        int height;
        int diameter;
};

HDpair diameter_optim(node* root){
    HDpair p;
    if(!root){
        p.diameter=0;
        p.height=0;
        return p;
    }

    HDpair l=diameter_optim(root->left);
    HDpair r=diameter_optim(root->right);
    p.height=max(l.height,r.height)+1;
    
    int d1=l.height+r.height;
    int d2=l.diameter;
    int d3=r.diameter;
    p.diameter=max({d1,d2,d3});
    return p;
}
int main(){
    node* root=build();
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    cout<<diameter_optim(root).diameter<<endl;
    return 0;
}