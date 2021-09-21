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

int height(node* root){
    if(!root) return 0;
    return max(height(root->left),height(root->right))+1;
}

bool isheightbalanced(node* root){
    if(!root) return true;
    int left=height(root->left);
    int right=height(root->right);
    return abs(left-right)<=1 and isheightbalanced(root->left) and isheightbalanced(root->right);
}

//---------
pair<int,bool> isheightbalanced_optim(node* root){
    pair<int,bool> p;
    if(!root){
        p.first=0;
        p.second=1;
        return p;
    }
    pair<int,bool> left=isheightbalanced_optim(root->left);
    pair<int,bool> right=isheightbalanced_optim(root->right);
    p.first=max(left.first,right.first)+1;
    p.second=abs(left.second-right.second)<=1 and left.second and right.second;
    return p;
}

int main(){
    node* root=build();
    cout<<isheightbalanced(root)<<endl;
    return 0;
}