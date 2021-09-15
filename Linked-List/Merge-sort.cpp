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

node* merge(node* a,node* b){
    if(!a) return b;
    if(!b) return a;

    node* res;
    if(a->data<b->data){
        res=a;
        res->next=merge(a->next,b);
    }
    else{
        res=b;
        res->next=merge(a,b->next);
    }
    return res;
}
node* midpoint(node* head){
    node* slow=head;
    node* fast=head->next;
    while(fast and fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node* mergesort(node* &head){
    if(!head or !head->next) return head;
    node *mid=midpoint(head);
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;
    a=mergesort(a);
    b=mergesort(b);
    return merge(a,b);
}
void print(node* head){
    if(!head) return;
    cout<<head->data<<" ";
    print(head->next);
}

int main(){
    node* head=NULL,*last=NULL;
    int d;
    while(1){
        cin>>d;
        if(d==-1) break;
        create(head,last,d);
    }
    head=mergesort(head);
    print(head);cout<<endl;
    return 0;
}