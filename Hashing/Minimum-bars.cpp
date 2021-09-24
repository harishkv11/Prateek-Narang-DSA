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

int helper(string s,vector<string> v,int idx,unordered_set<string> &m){
    if(s[idx]=='\0') return 0;
    int ans=INT_MAX;
    
    string curr="";
    for(int j=idx;s[j]!='\0';j++){
        curr+=s[j];
        if(m.find(curr)!=m.end()){
            int remain=helper(s,v,j+1,m);
            if(remain!=-1) ans=min(ans,remain+1);
        }
    }
    if(ans==INT_MAX) return -1;
    return ans;
}

int solve(string s,vector<string> v){
    unordered_set<string> m;

    for(string t: v) m.insert(t);

    int output=helper(s,v,0,m);
    return output-1;
}
void solve(){
    string s;cin>>s;
    int n;cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];


    cout<<solve(s,v)<<endl;
}

int32_t main()
{
    hkv();
    //solve();
    w(t) solve();
    return 0;
}