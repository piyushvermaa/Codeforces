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

void build(vector<int>& arr, vector<ll>& seg, int low, int high, int idx){
    if(low==high){
        seg[idx]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(arr,seg,low,mid,2*idx+1);
    build(arr,seg,mid+1,high,2*idx+2);

    seg[idx]=__gcd(seg[2*idx+1],seg[2*idx+2]);
}

ll query(int l, int r, int low, int high, int idx, vector<ll>& seg){
    // no overlap
    if(r<low or high<l) return 0;
    // complete overlap
    if(low>=l and high<=r) return seg[idx];

    // partial overlap
    int mid=(low+high)/2;
    ll left=query(l,r,low,mid,2*idx+1,seg);
    ll right=query(l,r,mid+1,high,2*idx+2,seg);
    return __gcd(left, right);
}

void update(int idx, int val, int low, int high, int i, vector<ll>& seg){
    if(low==high){
        seg[i]=val;
        return;
    }
    int mid=(low+high)/2;
    if(idx<=mid) update(idx, val, low, mid, 2*i+1,seg);
    else update(idx,val,mid+1,high,2*i+2,seg);

    seg[i]=__gcd(seg[2*i+1],seg[2*i+2]);
}

int find(int i, int low, int high, int l, int h, int x, vector<ll>& seg){
    // no overlap
    if(h<low or high<l) return 0;
    if(low==high){
        return seg[i]%x?1:0;
    }
    if(low>=l && high<=h && seg[i]%x==0) return 0;
    int mid=(low+high)/2;
    int left=find(2*i+1,low,mid,l,h,x,seg);
    if(left>1) return left;
    int right=find(2*i+2,mid+1,high,l,h,x,seg);
    return left+right;
}

void solve(){
    int n,q; cin>>n;
    vector<int> arr(n);
    for(auto& i: arr) cin>>i;
    vector<ll> seg(4*n);
    build(arr,seg,0,n-1,0);
    cin>>q;
    while(q-->0){
        int type; cin>>type;
        if(type==1){
            int l,r,guess; cin>>l>>r>>guess;
            int ans=query(l-1,r-1,0,n-1,0,seg);
            if(ans%guess==0) yes();
            else{
                if(find(0,0,n-1,l-1,r-1,guess,seg)==1) yes();
                else no();
            }
        }else{
            int idx, val; cin>>idx>>val;
            update(idx-1, val, 0, n-1,0,seg);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T=1;
    // cin >> T;
    while (T>0 && T--) {
        solve();
    }
    return 0;
}
