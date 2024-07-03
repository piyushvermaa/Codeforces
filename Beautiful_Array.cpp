#include <bits/stdc++.h> 
using namespace std; 
 
#define int long long 
#define vi vector<int> 
 
void solve() { 
    int n, k;cin>>n>>k; 
    vi arr(n); 
    for(auto &i:arr) cin>>i; 
     
    map<int, set<int>> mp; 
    for(auto it : arr) { 
        if(mp[it % k].find(it)!= mp[it % k].end())mp[it % k].erase(it); 
        else mp[it % k].insert(it);
    }
     
    int cnt = 0, rem = -1; 
    for(auto &x : mp) { 
        int s= x.second.size(); 
        if(s%2) { 
            cnt++; 
            rem = x.first; 
        } 
    } 
    if(cnt > 1) { 
        cout<<-1 << endl; 
        return; 
    } 
     
    int ans = 0; 
    for(auto &it : mp) { 
        if(it.first == rem) continue; 
        while(it.second.size() > 0) { 
            int b = *it.second.begin(); 
            it.second.erase(b); 
            if(it.second.size() == 0) break; 
            int tp = *it.second.begin(); 
            it.second.erase(tp); 
            ans += (tp - b) / k; 
        } 
    }
     
    if(cnt) { 
        vi v; 
        for(auto& x : mp[rem]) v.push_back(x); 
        int m = v.size(); 
        if(m== 1) { 
            cout << ans << endl; 
            return; 
        } 
        vi pre(m, 0), suff(m, 0); 
        pre[1] = v[1] - v[0]; 
        for(int i = 3; i < m; i += 2) { 
            pre[i] = v[i] - v[i - 1] + pre[i - 2]; 
        } 
        suff[m - 2] = v[m - 1] - v[m - 2]; 
        for(int i = m - 4; i >= 0; i -= 2) { 
            suff[i] = v[i + 1] - v[i] + suff[i + 2]; 
        } 
        int temp = LLONG_MAX; 
        for(int i = 0; i < m; i += 2) { 
            int x = 0; 
            if(i > 0) x += pre[i - 1]; 
            if(i + 1 < m) x += suff[i + 1]; 
            temp = min(temp, x); 
        } 
        ans += temp / k; 
    } 
    cout<<ans<<endl; 
} 
int32_t main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
     
    int t; 
    cin >> t; 
    for(int i = 0; i < t; i++) { 
        solve(); 
    } 
     
    return 0; 
}