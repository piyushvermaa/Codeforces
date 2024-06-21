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

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* createTree(const vector<int>& arr, int i) {
    if (i >= arr.size() or arr[i] == -1) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
}

void allnodes(Node* root, map<int, Node*>& mp){
    if(root!=nullptr){
        mp[root->data]=root;
        allnodes(root->left, mp);
        allnodes(root->right, mp);
    }
}
//aag nei. me fail rhi 1 unit me apne nei. pe lga dega aag
ll aaglgado(queue<pair<Node*, int>>& q, map<Node*, int>& jalgye){
    ll time=0;
    while(!q.empty()){
        Node* curr=q.front().first;
        int iskatime=q.front().second;
        q.pop();
        time+= curr->data*iskatime;
        vector<Node*> padosi={curr->left, curr->right};
        for(auto& x: padosi){
            if(x){
                //agar ab tk nh jla
                if(jalgye.find(x)==jalgye.end()){
                    q.push({x,iskatime+1});
                    //ye bhi gya
                    jalgye[x]=iskatime+1;
                }
            }
        }
    }
    return time;
}

    map<Node*, int> jalgye;
long long ans(Node* root,vector<int>& brr, map<int, Node*>& mp){
    queue<pair<Node*, int>> q;
    //shuru me jali hui nodes q. me 
    for(auto& x: brr){
        if(mp.find(x)!=mp.end()){
            Node* curr=mp[x];
            q.push({curr,0});
            jalgye[curr]=0;
        }
    }
    ll x=aaglgado(q,jalgye);
    return x;
}

void solve(){
    int n, k; cin>>n>>k;
    vi arr(n), brr(k);
    for(auto& i: arr) cin>>i;
    for(auto& i: brr) cin>>i;
    
    Node* root= createTree(arr, 0);

    map<int, Node*>mp;
    allnodes(root,mp);

    ll ans=0;
    for(auto& i: arr) {
        Node* curr=mp[i];
        ans+= jalgye[curr]*curr->data;
    }
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
    // cin >> T;
    while (T>0 && T--) solve();

    return 0;
}