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

/*
x<y<z

for last two element if they are decreasing i cant make it increasing as i cant choose three ele
i dont have to minimize no. of operation & there is no case of strictly increasing so i will try to make first n-2 ele equal or equal to y->(n-1) - z->(n)

5 -4 2 -1 2
y=-1 z=2
y-z=-1-2=-3

-3 -3 -3 -1 2 bn gyi non decreasing

*/

void solve(){
    ll n; cin>>n;
    vll arr(n);
    for(auto& i: arr) cin>>i;
    if(arr[n-2]>arr[n-1]){
        cout<<-1<<endl;
        return;
    }
    //dekh yrr agar last element neg hua toh y-z positive bn jaega ya y se chota bn jaega toh usko me y se pehle nh rakh sakta magar maan le pehle se sorted array hai toh koi dikkat nahi hai like -3 -2 -1 
    if(arr[n-1]<0){
        if(is_sorted(arr.begin(), arr.end())){
            cout<<0<<endl;
            return;
        }else{
            cout<<-1<<endl;
            return;
        }
    }

    // puri array me y-z rakh deta hu 1 se n-2 tk
    cout<<n-2<<endl;
    for(int i=1;i<=n-2;++i) cout<<i<<" "<<n-1<<" "<<n<<endl;
    
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