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
jo double baar arrhe hai un no. ko preseve krna pdea
if saare hi ek baare aaye
5 3 4 2 1

to simple same same rakhdo
5 3 4 2 1
5 3 4 2 1

but same ele repeat hoga tb dekhna pdega
5 3 4 2 5
5
        5


sets ka use kr skta hu
pehle repeat walo ko place krdunga 
then sets me se ele dhund lunga


*/

void solve(){
    ll n; cin>>n;
    bool flag=false;
    map<int,vector<int>> mp; //ele, kha kha vo aya 
    vll a(n,-1),b(n,-1), arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
        mp[arr[i]].push_back(i);
        //agar ele 2 s jda aagya of simply no
        if(mp[arr[i]].size()>2){
           flag=true;
        }   
    }
    if(flag){
        no();
        return;
    }
    //double walo ko place krte ek ko a me ek ko b me
    for(auto& it: mp){
        int ele=it.first;
        vector<int> idxs=it.second;
        if(idxs.size()==2){
            b[idxs[0]]=ele;
            a[idxs[1]]=ele;
        }
    }
    set<int> s1,s2;
    for(int i=1;i<=n;++i){
        s1.insert(i);
        s2.insert(i);
    }
    for(int i=0;i<n;++i){
        if(a[i]!=-1) s1.erase(a[i]);
        if(b[i]!=-1) s2.erase(b[i]);
    }

    //ab sets m bcche hue ele honge jinhe use kr skta hu i will try to place same ele  if not exist then i will try for smaller ones
    // but chote elements ko pehle satisy krvana pdega 
    vector<pair<int,int>> v; // element with index isko sort krlenge or index ka use krke settle

    for(int i=0;i<n;++i){
        v.push_back({arr[i],i});
    }
    sort(v.begin(), v.end());
    //set ki sbse choti vals se satify krvaenge

    for(auto& it: v){
        int val=it.first;
        int idx=it.second;
        //agar a or b dono me -1 hai to set1 ya set2 me voh val present hona chahiye or durse set me bhi ya usse se chota mil jae
        if(a[idx]==-1 and b[idx]==-1){
            int c1= *s1.begin();
            int c2= *s2.begin();
            if(s1.find(val)!=s1.end() and c2<=val){
                a[idx]=val;
                b[idx]=c2;
                s1.erase(val);
                s2.erase(c2);
            }else if(s2.find(val)!=s2.end() and c1<=val){
                a[idx]=c1;
                b[idx]=val;
                s1.erase(c1);
                s2.erase(c2);
            }else{
                no();
                return;
            }
        }if(a[idx]==-1){
            int x=*s1.begin();
            if(x<=b[idx]) a[idx]=x;
            else {no(); return;}
            s1.erase(x);
        }else if(b[idx]==-1){
            int y=*s2.begin();
            if(y<=a[idx]) b[idx]=y;
            else{no(); return;}
            s2.erase(y);
        }
    }
    yes();
    for(auto& i: a) cout<<i<<" ";
    cout<<endl;
    for(auto& i: b) cout<<i<<" ";
    cout<<endl;
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