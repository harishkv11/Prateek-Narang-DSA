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
int inversion_count(vector<int> &a,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int> temp;
    int cnt=0;
    while(i<=m and j<=e){
        if(a[i]>a[j]){
            temp.push_back(a[j]);
            cnt+=(m-i+1);
            j++;
        }
        else{
            temp.push_back(a[i]);
            i++;
        }
    }
    while(i<=m) temp.push_back(a[i++]);
    while(j<=e) temp.push_back(a[j++]);
    int k=0;
    for(int i=s;i<=e;i++) a[i]=temp[k++];
    return cnt;
}
int inversion(vector<int> &a,int s,int e){
    if(s>=e) return 0;
    int mid=(s+e)/2;
    int c1=inversion(a,s,mid);
    int c2=inversion(a,mid+1,e);
    int c3=inversion_count(a,s,e);
    return c1+c2+c3;
}
void solve(){
    arr(a,n);
    int ans=inversion(a,0,n-1);
    cout<<ans<<endl;
}

int32_t main()
{
    hkv();
    solve();
    //w(t) solve();
    return 0;
}