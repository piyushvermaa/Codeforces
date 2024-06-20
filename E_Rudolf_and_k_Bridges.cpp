#include "bits/stdc++.h"
using namespace std;

#define INF 1000000000000000003
#define PI 3.1415926535897932384626433832795
#define mod 1e9 + 7

#define F first
#define S second
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mkp make_pair
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define pob pop_back
#define eb emplace_back

#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void solve(){
    ll n, m, k, d; cin>>n>>m>>k>>d;
    vector<vll> mat(n, vll(m, 0));
    for(auto& i: mat){
        for(auto& j: i) cin>>j;
    }
    // for(auto& i: mat){
    //     for(auto& j: i) cout<<j<<" ";
    //     cout<<endl;
    // }
    vll costofrow(n);
    for(int i=0;i<n;++i){
        multiset<ll> subs;
        vll dp(m,0);
        dp[0]=1; // pehle akhri pe 1 1 lgana hi h
        subs.insert(1);
        for(int j=1;j<m;++j){
            dp[j]= *subs.begin() + mat[i][j] + 1;
            subs.insert(dp[j]);
            if(j-d>=1) subs.erase(subs.find(dp[j-d-1]));
        }
        costofrow[i]=dp.back();
    }
    // for(auto& i: costofrow) cout<<i<<" ";
    // cout<<endl;
/*
    k consecutive rows
    6    4  4   6
 0  6   10 14  20
        10  8   10

    prefix array
*/

    vector<uint64_t> pre(costofrow.size()+1,0);
    for(int i=1;i<=costofrow.size();++i) pre[i]=pre[i-1]+costofrow[i-1];

    // for(auto& i: pre) cout<<i<<" ";
    // cout<<endl;

    uint64_t ans=INF;
    for(int i=k;i<=costofrow.size();++i) ans=min(ans, pre[i]-pre[i-k]);
    cout<<ans<<endl;
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T=1;
    cin >> T;
    while (T>0 && T--) solve();

    return 0;
}