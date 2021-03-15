#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 100007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, t;

vector<int> e[N], rev[N], g[N];
int vis[N], col[N], cnt[N], f[N];

// f[col] = se dali pra baixo tem alguma aresta pra 

vector<int> topo;
void dfs(int u) {
    vis[u] = 1;

    for(int v : e[u]) {
        if(v == t) continue;
        if(vis[v] == 0) dfs(v);
    }

    topo.pb(u);
}

void colorfy(int u, int c) {
    col[u] = c;
    
    for(int v : rev[u]) {
        if(v == t) continue;
        if(col[v] == 0) colorfy(v, c);
    }
}

int below(int u) {
    int & st = f[u];
    if(st == -1) {
        st = 0;
        for(int v : g[u]) {
            st = st or cnt[v] or below(v);
        }
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> t;


    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;

        e[u].pb(v);
        rev[v].pb(u);
    }

    for(int u = 0; u < n; ++u) {
        if(u != t and vis[u] == 0) {
            dfs(u);
        }
    }

    reverse(topo.begin(), topo.end());

    int c = 0;

    for(int u : topo) {
        if(col[u] == 0)
            colorfy(u, ++c);
    }

    for(int u = 0; u < n; ++u) {
        if(u == t) continue;
        for(int v : e[u]) {
            if(v != t) {
                if(col[u] != col[v]) {
                    g[col[u]].pb(col[v]);
                }  
            } else {
                cnt[col[u]]++;
            }
        }
    }

    memset(f, -1, sizeof f);
    
    vector<int> ans;
    for(int u = 0; u < n; ++u) {
        if(u == t) continue;
        for(int v : e[u]) {
            if(v == t) {
                if(cnt[col[u]] == 1 and below(col[u]) == 0) {
                    ans.pb(u);
                } 
            } 
        }
    }
    cout << ans.size() << endl;
    for(int x : ans) cout << x << '\n';
}