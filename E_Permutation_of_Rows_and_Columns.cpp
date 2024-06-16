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
    int n,m; cin>>n>>m;
    vector<vector<int>> src(n, vector<int>(m)), des(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>src[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>des[i][j];
        }
    }
    map<int, vector<int>> c1,c2;
    for(int i=0; i<m; i++){
        vi arr;
        int mini=INT_MAX;
        for(int j=0; j<n; j++){
            mini=min(mini, src[j][i]);
            arr.push_back(src[j][i]);
        }
        c1[mini]=arr;
    }
    for(int i=0; i<m; i++){
        vi arr;
        int mini=INT_MAX;
        for(int j=0; j<n; j++){
            mini=min(mini, des[j][i]);
            arr.push_back(des[j][i]);
        }
        c2[mini]=arr;
    }
    for(auto& it: c1){
        if(c2.find(it.first)==c2.end()){
            no();
            return;
        }else{
            vi a=it.second;
            vi b=c2[it.first];
            sort(all(a));
            sort(all(b));
            for(int i=0;i<a.size();++i){
                if(a[i]!=b[i]){
                    no();
                    return;
                }
            }
        }
    }

    map<int, vector<int>> r1,r2;
    for(int i=0; i<n; i++){
        vi arr;
        int mini=INT_MAX;
        for(int j=0; j<m; j++){
            mini=min(mini, src[i][j]);
            arr.push_back(src[i][j]);
        }
        r1[mini]=arr;
    }
    for(int i=0; i<n; i++){
        vi arr;
        int mini=INT_MAX;
        for(int j=0; j<m; j++){
            mini=min(mini, des[i][j]);
            arr.push_back(des[i][j]);
        }
        r2[mini]=arr;
    }
    for(auto& it: r1){
        if(r2.find(it.first)==r2.end()){
            no();
            return;
        }else{
            vi a=it.second;
            vi b=r2[it.first];
            sort(all(a));
            sort(all(b));
            for(int i=0;i<a.size();++i){
                if(a[i]!=b[i]){
                    no();
                    return;
                }
            }
        }
    }
    
    
    yes();
    
    
    
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