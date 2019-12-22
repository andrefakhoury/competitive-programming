#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG false
#define ll long long
typedef pair<int, int> pii;
 
const int INF = 200;
const int MAXN = 500 + 5;
 
int a[MAXN], id[MAXN], rv[MAXN];
bool vis[MAXN];
 
vector<int> edges[MAXN];
 
int dfs(int u) {
    if (vis[u]) return INF;
    vis[u] = true;
 
    int ret = INF;
 
    for (int v : edges[u]) {
        ret = min(ret, a[id[v]]);
        ret = min(ret, dfs(v));
    }
 
    return ret;
}
 
int main() {
    int n, m, q;
    
    while (~scanf("%d%d%d", &n, &m, &q)) {
        for (int i = 1; i <= n; i++) scanf("%d", a+i);
        for (int i = 1; i <= n; i++) id[i] = i, rv[i] = i;
 
        char op;
        int u, v, x, ans;
 
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            edges[v].pb(u);
        }
 
        while(q--) {
            scanf(" %c", &op);
 
            if (op == 'T') {
                scanf("%d%d", &u, &v);
                swap(id[rv[u]], id[rv[v]]);
                swap(rv[u], rv[v]);
            } else {
                scanf("%d", &x);
                memset(vis, 0, sizeof vis);
                ans = dfs(rv[x]);
 
                if (ans == INF) printf("*\n");
                else printf("%d\n", ans);
            }
        }
    }
 
   return 0;
}