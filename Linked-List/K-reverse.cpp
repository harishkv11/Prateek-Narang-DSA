#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};

void create(node* &head,node* &last,int x){
    node* n= new node(x);
    if(!head){
        head=last=n;
    }
    else{
        last->next=n;
        last=n;
    }
}

void insertathead(node* &head,int x){
    node* n=new node(x);
    if(!head) head=n;
    else{
        n->next=head;
        head=n;
    }
}

node* reverserec(node* &head){
    if(!head or !head->next) return head;
    node* res=reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return res;
}

node* reverseiter(node* &head){
    node *t=NULL,*p=head,*q;
    while(p){
        q=p->next;
        p->next=t;
        t=p;
        p=q;
    }
    return t;
}

node* kreverse(node* &head,int k){
    node *n=NULL,*prev=NULL,*curr=head;
    int count=0;
    while(curr and count<k){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
        count++;
    }
    if(n) head->next=kreverse(n,k);
    return prev;
}

void print(node* head){
    if(!head) return;
    cout<<head->data<<" ";
    print(head->next);
}
int main(){
    node* head=NULL,*last=NULL;
    int x;
    while(1){
        cin>>x;
        if(x==-1) break;
        create(head,last,x);
    }
    print(head);cout<<endl;
    int k;cin>>k;
    head=kreverse(head,k);
    print(head);cout<<endl;
    return 0;
}