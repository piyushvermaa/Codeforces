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

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = createNode(data);
            return root;
        }
        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = createNode(data);
            return root;
        }
    }
    return root;
}

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int countUnevenNodes(Node *root, int k)
{
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) >= k)
        return 1 + countUnevenNodes(root->left, k) + countUnevenNodes(root->right, k);
    else
        return countUnevenNodes(root->left, k) + countUnevenNodes(root->right, k);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = insertNode(root, data);
    }
    int unevenNodes = countUnevenNodes(root, k);
    cout << unevenNodes << endl;
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
    // cin >> T;
    while (T > 0 && T--)
        solve();

    return 0;
}