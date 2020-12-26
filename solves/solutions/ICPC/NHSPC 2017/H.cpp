#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int N = 1000007, inf = 0x3f3f3f3f, M = 1000000007;

using namespace std;
typedef long long ll;
typedef pair<int, int > ii;

vector<int> e[N], c[N];

ll cnt[N], com[N];
int pai[N];

ll mul(ll a, ll b) {
    a%=M, b%=M;
    return (a * b)%M;
}

ll sum(ll a, ll b) {
    return ((a%M) + (b%M) + M)%M;
}

ll l[N];
void dfs(int u, int par = -1, int w = -1, int lev = 0) {
    cnt[u] = 1;
    com[u] = w;
    pai[u] = par;
    l[u] = lev;

    for(int i = 0; i < e[u].size(); ++i) {
        int w = c[u][i];
        int v = e[u][i];
        if(v == par) continue;
        dfs(v, u, w, lev + 1);
        cnt[u] += cnt[v];
        cnt[u] %= M;
    }
}

ll ans = 0;

ll f[N];

void build(int u, ll cur = 0) {
    f[u] = cur;
    for(int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if(v == pai[u]) continue;
        build(v, sum(cur, cnt[u]));
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    int caso = 1;
    while(t--) {
        int n; cin >> n;

        for(int i = 1; i <= n; ++i) e[i].clear(), c[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].pb(v);
            c[u].pb(w);
            e[v].pb(u);
            c[v].pb(w);
        }

        
        dfs(1);
        build(1);

        ans = 0;
        for(int u = 2; u <= n; ++u) {
            ll w = com[u];
            ll res = 0;
            res += mul(cnt[u],  f[u]);
            res %= M;
            res -= mul(l[u], mul(cnt[u], cnt[u]));
            res += M;
            res %= M;
            ans += mul(res, w);
            ans %= M;
        }
        cout << "Case " << caso << ": " << ans << endl; 
        caso++;
    }

}