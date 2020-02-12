#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 5e5 + 5, INF = 0x3f3f3f3f;
 int p[MAXN];
 struct UF {
    int par[MAXN], ans[MAXN];
     void init() {
        for (int i = 0; i < MAXN; i++) {
            par[i] = i;
            ans[i] = p[i];
        }
    }
     int find(int x) {
        if (par[x] == x) return x;
        return find(par[x]);
    }
     void merge(int u, int v) {
        // int a = find(u), b = find(v);
        par[v] = u;
         // par[b] = a;
        // ans[a] = min(ans[a], ans[b]);
    }
     pii query(int u) {
        if (par[u] == u) return {ans[u] = p[u], u};
        pii cur = query(par[u]);
         ans[u] = min(ans[u], cur.fi);
        par[u] = cur.se;
                return {ans[u], par[u]};
    }
};
 int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
     int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
        UF uf;
    uf.init();
     while(m--) {
        char op; cin >> op;
        int u, v; cin >> u;
         if (op == '?') {
            cout << uf.query(u).fi << '\n';
        } else {
            cin >> v;
            uf.merge(u, v);
        }
    }        
     return 0;
}