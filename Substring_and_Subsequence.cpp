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

#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back
#define pob pop_back
#define eb emplace_back

#define read(type) readInt<type>()
ll min(ll a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll min(int a, ll b)
{
    if (a < b)
        return a;
    return b;
}
ll max(ll a, int b)
{
    if (a > b)
        return a;
    return b;
}
ll max(int a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int lcs(const string &a, const string &b) {
    int n= a.size();
    int m= b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i=1;i<=n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1]==b[j - 1]) {
                dp[i][j]=dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j]=max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

void solve() {
    string a, b; cin>>a>>b;
    int ans=a.size()+b.size();
    for (int start = 0; start <= b.size(); ++start) {
        int matchCount = 0;
        for (int i1 = 0, i2 = start; i1 < a.size() and i2 < b.size(); ++i1) {
            if (a[i1] == b[i2]) {
                ++matchCount;
                ++i2;
            }
        }
        int currentLength = a.size() + (b.size() - matchCount);
        ans = min(ans, currentLength);
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    int T = 1;
    cin >> T;
    while (T > 0 && T--)
        solve();

    return 0;
}