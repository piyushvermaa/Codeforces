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

int maxmatch(string& a, string& b){
    int i=0;
    int cnt=0;
    while(i<a.size()){
        if(a[i]==b[i]) ++cnt;
        ++i;
    }
    return cnt;
}

void solve(){
    int n, m; cin>>n>>m;
    string s, t; cin>>s>>t;
    vi ans;
    for(int i=0;i+n<=m;++i){
        vi diffs;
        for(int j=0;j<n;++j){
            if(s[j]!=t[i+j]) diffs.push_back(j+1);
        }
        if(i==0 or ans.size()>diffs.size()) ans=diffs;
    }
    cout<<ans.size()<<endl;
    for(auto& i: ans) cout<<i<<" ";
    cout<<endl;

    // string maxis="";
    // //har n size ki window check krleta hu max kis window me match horhe

    
    // for(int i=0;i+n<=m;++i){
    //     string sub = t.substr(i, n);
    //     int cntt=maxmatch(s,sub);
    //     if(cntt>maxi){
    //         maxi=cntt;
    //         maxis=sub;
    //     }
    // }

    // vi ans;
    // for(int i=0;i<n;++i){
    //     if(s[i]!=maxis[i]) ans.push_back(i+1);
    // }
    // cout<<ans.size()<<"\n";
    // for(auto& i: ans) cout<<i<<" ";


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
    // cin >> T;
    while (T>0 && T--) solve();

    return 0;
}