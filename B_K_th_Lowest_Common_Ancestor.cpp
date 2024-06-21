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

Node* lca(Node* root, int p, int q) {
    if (!root or root->data == p or root->data == q) return root;
    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);
    if (left and right) return root;
    return left ? left : right;
}

bool findPath(Node* root, int target, vector<Node*>& path) {
    if (!root) return false;
    path.push_back(root);
    if (root->data == target) return true;
    if ((root->left and findPath(root->left, target, path)) or (root->right and findPath(root->right, target, path))) return true;
    path.pop_back();
    return false;
}

Node* ans(Node* root, int target, int k) {
    vector<Node*> path;
    if (!findPath(root, target, path)) return nullptr;
    int path_size = path.size();
    return (k < path_size) ? path[path_size - k - 1] : nullptr;
}

int lca(Node* root, int p, int q, int k) {
    Node* lcaa = lca(root, p, q);
    if (!lcaa) return -1;
    Node* kth = ans(root, lcaa->data, k);
    return kth? kth->data : -1;
}


void solve(){
    int n, m, k; cin>>n>>m>>k;
    vi arr(n);
    for(auto& i: arr) cin>>i;

    vector<pair<int, int>> pairs(m);
    for (int i = 0; i < m; ++i) cin>>pairs[i].first>>pairs[i].second;

    Node* root = createTree(arr, 0);

    for (auto& p : pairs) {
        int p1=p.first;
        int p2=p.second;
        int res= lca(root, p1, p2, k);
        cout<<res<<endl;
    }
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