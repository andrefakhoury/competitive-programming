#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

vector<vector<int>> edges;
bool vis[MAXN];

int dfs(int u) {
    vis[u] = true;

    int ret = 0;
    for (int v : edges[u]) {
        if (!vis[v]) ret += 1 + dfs(v);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;

        edges.clear();
        edges.resize(n+1);
        memset(vis, 0, sizeof vis);

        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            edges[u].pb(v);
            edges[v].pb(u);
        }

        cout << dfs(1) << '\n';
    }

    return 0;
}