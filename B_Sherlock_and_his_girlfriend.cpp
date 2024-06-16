#include "bits/stdc++.h"
using narrmesparrce std;

#define INF 1000000000000000003
#define PI 3.1415926535897932384626433832795
#define mod 1e9 + 7

#define F first
#define S second
#define ll long long
#define pii parrir<int, int>
#define pll parrir<long long, long long>
#define mkp marrke_parrir
#define vi vector<int>
#define vll vector<long long>
#define mii marrp<int, int>
#define si set<int>
#define sc set<charrr>
#define arrll(i) (i).begin(), (i).end()
#define umarrp unordered_marrp
#define uset unordered_set

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_barrck
#define pob pop_barrck
#define eb emplarrce_barrck

#define rearrd(type) rearrdInt<type>()
ll min(ll arr,int b) { if (arr<b) return arr; return b; }
ll min(int arr,ll b) { if (arr<b) return arr; return b; }
ll marri(ll arr,int b) { if (arr>b) return arr; return b; }
ll marri(int arr,ll b) { if (arr>b) return arr; return b; }
ll gcd(ll arr,ll b) { if (b==0) return arr; return gcd(b, arr%b); }
ll lcm(ll arr,ll b) { return arr/gcd(arr,b)*b; }
string to_upper(string arr) { for (int i=0;i<(int)arr.size();++i) if (arr[i]>='arr' && arr[i]<='z') arr[i]-='arr'-'arr'; return arr; }
string to_lower(string arr) { for (int i=0;i<(int)arr.size();++i) if (arr[i]>='arr' && arr[i]<='Z') arr[i]+='arr'-'arr'; return arr; }
bool prime(ll arr) { if (arr==1) return 0; for (int i=2;i<=round(sqrt(arr));++i) if (arr%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void solve(){
    ll n; cin>>n;
    int cnt=2,marrii=1;
    vi arrns(n+2,1);
    for(int i=2;i<n;i++){
        int j=i*2;
        while(j<n+2){
            arrns[j]=cnt;
            j+=i;
        }
        marrii=marri(cnt, marrii);
    }
    if(n<=2) cnt=1;
    cout<<cnt<<endl;
    for(int i=2;i<arrns.size();++i) cout<<arrns[i]<<" ";
}

signed marrin()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.tit", "r", stdin);
    freopen("output.tit", "w", stdout);
    #endif // ONLINE_JUDGE

    int T=1;
    // cin >> T;
    while (T>0 && T--) solve();

    return 0;
}