#include <bits/stdc++.h>

#define int ll
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f3f3f3f3fll;
const int N = 307;
struct ed {
    int v, cap, f;
};

int cur = 0;
int s, t;
ed arestas[N * N * 2];
vector<int> edges[N];
int ptr[N], d[N];

void add_edge(int u, int v, int cap) {
    arestas[cur] = {v, cap, 0};
    edges[u].pb(cur);
    cur++;

    arestas[cur] = {u, cap, cap};
    edges[v].pb(cur);
    cur++;
}

int bfs() {
    int i, p, u, v;
    queue<int> q;
    memset(d, 0x3f, sizeof d);

    q.push(s);
    d[s] = 0;

    while(q.size()) {
        u = q.front();
        q.pop();

        for(i = 0; i < edges[u].size(); ++i) {
            p = edges[u][i];
            v = arestas[p].v;

            if(d[v] == inf and arestas[p].f < arestas[p].cap) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }    
    }

    return d[t] != inf;
}

int dfs(int u, int f) {
    if(f == 0) return 0;
    if(u == t) return f;

    int v, p;
    for(int & i = ptr[u]; i < edges[u].size(); ++i) {
        p = edges[u][i];
        v = arestas[p].v;
        if(d[v] == d[u] + 1) {
            int tot = dfs(v, min(f, arestas[p].cap - arestas[p].f));
            if(tot) {
                arestas[p].f += tot;
                arestas[p^1].f -= tot;
                return tot;
            }
        }
    }

    return 0;
}

int flow() {
    int f = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int tot = dfs(s, inf)) f += tot;
    }

    return f;
}

int cost[N], gain[N];

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int z, j; cin >> z >> j;

    for(int i = 1; i <= z; ++i) {
        cin >> cost[i];
    }

    int ans = 0;
    for(int i = 1; i <= j; ++i) {
        cin >> gain[i];
        ans += gain[i];
    }

    for(int i = 1; i <= j; ++i) {
        int m; cin >> m;
        for(int k = 0; k < m; ++k) {
            int x; cin >> x; // job i precisa da zona x
            add_edge(i, j + x, inf);
        }
    }

    s = 0, t = z + j + 1;
    for(int i = 1; i <= j; ++i) {
        add_edge(s, i, gain[i]);
    }

    for(int i = 1; i <= z; ++i) {
        add_edge(j + i, t, cost[i]);
    }

    int f = flow();
    cout << ans - f << endl; 
}