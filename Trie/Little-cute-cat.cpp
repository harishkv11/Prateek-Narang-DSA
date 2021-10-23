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

};

void searchHelper(trie t,string document,int i, unordered_map<string,bool> &m){
    node* temp=t.root;
    for(int j=i;j<document.length();j++){
        char ch=document[j];
        if(temp->m.count(ch)==0) return;
        temp=temp->m[ch];

        if(temp->isterminal){
            string out=document.substr(i,j-i+1);
            m[out]=true;
        }
    }
    return;
}

void documentsearch(string document,vector<string> words){
    //1. Create a trie of words
    trie t;
    for(string s: words) t.insert(s);

    //2.Searching 
    unordered_map<string,bool> m;
    for(int i=0;i<document.length();i++){
        searchHelper(t,document,i,m);
    }

    //3. You can check which words are marked as True inside Hashmap
    for(auto w: words){
        if(m[w]){
            cout<<w<<" True"<<endl;
        }
        else cout<<w<<" False"<<endl;
    }
}

int main(){
    string document;getline(cin,document);
    vector<string> words;
    int n;cin>>n;
    while(n--){
        string s;getline(cin,s);
        while(s.length()==0) getline(cin,s);
        words.push_back(s);
    }

    documentsearch(document,words);

    return 0;
}