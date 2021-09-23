#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0;i<n;i++)
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leadingzr(x)    __builtin_clz(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define arr(a,n)          int n;cin>>n;vector<int> a(n);for(int i=0;i<n;i++) cin>>a[i];
#define w(x)            int x; cin>>x; while(x--)
#define conarr(a,n,k)     int n,k;cin>>n>>k;vector<int> a(n);for(int i=0;i<n;i++) cin>>a[i];
#define range(x)           (x).begin(),(x).end()
#define endl            "\n"
#define total(x)        accumulate(x.begin(),x.end(),(int)0)
 
int add(int x,int y) {int res=x+y; return (res>=mod ? res-mod: res);}
int mul(int x,int y) {int res=x*y; return (res>=mod? res%mod : res);}
int sub(int x,int y) {int res=x-y; return (res<0?res+mod:res);}
int power(int x,int y) {int res=1; x%=mod; while(y){ if(y&1) res=mul(res,x); y>>=1; x=mul(x,x);} return res;}
int mod_inv(int x) {return power(x,mod-2);}

void hkv()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
}

//-----------debugging-------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//---------------------------------

class compare{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b){
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        }
};
void solve(){
    int n;cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v.push_back({x,y});
    }

    set<pair<int,int>,compare> s;
    for(auto x: v) s.insert(x);
    int ans=0;

    for(auto it=s.begin();it!=prev(s.end());it++){
        for(auto jt=next(it);jt!=s.end();jt++){
            
            pair<int,int> p1=*it;
            pair<int,int> p2=*jt;

            if(p1.first==p2.first or p1.second==p2.second) continue;

            pair<int,int> p3;
            p3.first=p1.first;
            p3.second=p2.second;

            pair<int,int> p4;
            p4.first=p2.first;
            p4.second=p1.second;

            if(s.find(p3)!=s.end() and s.find(p4)!=s.end()) ans++;
        }
    }

    cout<<ans/2<<endl;
}

int32_t main()
{
    hkv();
    //solve();
    w(t) solve();
    return 0;
}