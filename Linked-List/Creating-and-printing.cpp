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
    print(head);
    cout<<endl;
    int d;cin>>d;
    insertathead(head,d);
    print(head);
    cout<<endl;
    return 0;
}