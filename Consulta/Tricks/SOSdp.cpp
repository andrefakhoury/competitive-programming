#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int const maxn = 1e6+10;
int const maxb = 20;
int const maxbb = 1 << maxb;
int const mod = 1e9 + 7;
 
int v[maxn];
int b[maxbb];
 
ll fexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
 
[[ gnu::target("abm,bmi") ]]
int popcnt(int x) {
    return __builtin_popcount(x);
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        b[v[i]]++;
    }
 
    sort(v, v+n);
 
    for (int i = 0; i < maxb; i++) {
        for (int j = 0; j < maxbb; j++) {
            if (!(j&(1<<i))) {
                b[j] += b[j^(1<<i)];
            }
        }
    }
 
    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < maxbb; i++) {
        int sgn = popcnt(i) % 2 == 0? 1 : -1;
 
        ans += sgn*fexp(2, b[i]);
 
        if (ans >= mod) ans -= mod;
        if (ans < 0) ans += mod;
    }
 
    cout << ans%mod << "\n";
}
