#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        string key;
        int value;
        node(string key,int value){
            this->key=key;
            this->value=value;
        }
};

class LRUCache{
    public:
        int maxsize;
        list<node> l;
        unordered_map<string,list<node>::iterator> m;

        LRUCache(int maxsize){
            this->maxsize=maxsize>1?maxsize:1;
        }

        void insertkeyvalue(string key,int value){
            if(m.count(key)!=0){
                auto it=m[key];
                it->value=value;
            }
            else{
                if(l.size()==maxsize){
                    node last=l.back();
                    m.erase(last.key);
                    l.pop_back();
                }

                node n(key,value);
                l.push_front(n);
                m[key]=l.begin();
            }
        }

        int* getvalue(string key){
            if(m.count(key)!=0){
                auto it=m[key];
                int value = it->value;
                l.push_front(*it);
                l.erase(it);
                m[key]=l.begin();
                return &l.begin()->value;
            }
            return NULL;
        }

        string mostrecentkey(){
            return l.front().key;
        }
};

int main(){
    LRUCache lru(3);
    lru.insertkeyvalue("mango",10);
    lru.insertkeyvalue("apple",20);
    lru.insertkeyvalue("guava",30);

    cout<<lru.mostrecentkey()<<endl;

    lru.insertkeyvalue("mango",40);
    cout<<lru.mostrecentkey()<<endl;

    lru.insertkeyvalue("banana",20);
    if(lru.getvalue("apple")==NULL){
        cout<<"Apple doesn't exist"<<endl;
    }

    if(lru.getvalue("guava")==NULL){
        cout<<"Guava doesn't exist"<<endl;
    }

    if(lru.getvalue("banana")==NULL){
        cout<<"Banana doesn't exist"<<endl;
    }

    if(lru.getvalue("mango")==NULL){
        cout<<"Mango doesn't exist"<<endl;
    }
    return 0;
}