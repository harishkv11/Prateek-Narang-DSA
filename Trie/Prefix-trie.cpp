#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        char data;
        unordered_map<char,node*> m;
        bool isterminal;

        node(char x){
            data=x;
            isterminal=false;
     }

};

class trie{
    public:
        node* root;
    trie(){
        root = new node('\0');
    }

    void insert(string word){
        node* t=root;
        for(char x: word){
            if(t->m.count(x)==0){
                node* n = new node(x);
                t->m[x]=n;
            }
            t=t->m[x];
        }

        t->isterminal=true;
    }

    bool search(string word){
        node* t=root;
        for(char x: word){
            if(t->m.count(x)==0){
                return false;
            }
            t=t->m[x];
        }

        return t->isterminal;
    }
};

int main(){
    trie t;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        t.insert(s);
    }

    int q;cin>>q;
    while(q--){
        string s;cin>>s;
        if(t.search(s)) cout<<s<<" is present"<<endl;
        else cout<<s<<" is not present"<<endl;
    }
    cout<<endl;
}