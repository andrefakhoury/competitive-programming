#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug false
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 6e4 + 10;

struct MCMF {
    struct Edge {
        int to, cost, cap, flow, rid;

        Edge() {}

        Edge(int a, int b, int c, int d, int e) :  
            to(a), cost(b), cap(c), flow(d), rid(e) {}
        
    };
    vector<Edge> edges[MAXN];
    int h[MAXN], dist[MAXN];
    ii par[MAXN];

    int n, s, t;

    inline MCMF(int n, int s, int t) : n(n), s(s), t(t) {
    }

    inline void add_edge(int u, int v, int cost, int cap) {
        edges[u].eb(v, cost, cap, 0, edges[v].size());
        edges[v].eb(u, -cost, 0, 0, (int) edges[u].size() - 1);
    }

    inline void bellman_ford(int s) {
        memset(h, 0x3f, sizeof h);

        h[s] = 0;
        priority_queue<ii> pq;
        pq.emplace(0, s);

        while(pq.size()) {
            int u = pq.top().se;
            int d = pq.top().fi;
            pq.pop();

            if (h[u] != d) continue;
            for (auto ed : edges[u]) {
                int v = ed.to, w = ed.cost;
                if (h[v] > h[u]+w) {
                    h[v] = h[u] + w;
                    pq.emplace(-h[v], v);
                }
            }
        }
    } 

    inline bool dijkstra(int s, int t) {
        memset(dist, 0x3f, sizeof dist);
        memset(par, -1, sizeof par);

        priority_queue<ii, vector<ii>, greater<ii> > pq;

        dist[s] = 0;
        pq.emplace(0, s);
        bool ret = false;

        while(pq.size()) {
            int at = pq.top().se, d = pq.top().fi;
            pq.pop();

            if(at == t) ret = true;
            if(d != dist[at]) continue;

            for(int i = 0; i < (int) edges[at].size(); ++i) {
                Edge edg = edges[at][i];
                int next = edg.to;
                if(edg.cap <= edg.flow) continue;

                int w = dist[at] + edg.cost + h[at] - h[next];

                if(dist[next] > w) {
                    dist[next] = w;
                    par[next] = ii(at, i);
                    pq.emplace(dist[next], next);
                }
            }
        }

        for(int i = 0; i <= n; ++i) {
            if(h[i] < INF and dist[i] < INF) {
                h[i] += dist[i];
            }
        }
        
        return ret;
    }

    inline ii max_flow() {
        int cost = 0, flow = 0;

        bellman_ford(s);

        while(dijkstra(s, t)) {
            int f = INF;
            for(int at = t; at != s; at = par[at].fi) {
                Edge edg = edges[par[at].fi][par[at].se];
                f = min(f, edg.cap - edg.flow);
            }
            flow += f;
            for(int at = t; at != s; at = par[at].fi) {
                Edge & edg = edges[par[at].fi][par[at].se];
                edg.flow += f;
                edges[edg.to][edg.rid].flow -= f;
                cost += edg.cost * f;
            }
        }
        return ii(cost, flow);
    }
};

void dfs(MCMF & f, int u, int t, int n, vector<int> & path) {
    if(u == t) return;
    for(int i = 0; i < (int) f.edges[u].size(); ++i) {
        MCMF::Edge edg = f.edges[u][i];
        int v = edg.to;
        if(edg.flow == 1) {
            if(abs(u - v) == n) {
                path.pb(min(u, v));
            }
            dfs(f, v, t, n, path);
        }
    }
}

int main() {	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m; cin >> n >> m;

    int a, b, c; cin >> a >> b >> c;

    int s = 0, t = 2 * n + 7;
    MCMF f(2 * n + 7, s, t);
    for(int i = 1; i <= n; ++i) {
        if(i != c) f.add_edge(i, i + n, 0, 1);
        else f.add_edge(i, i + n, 0, 2);
    }
    for(int i = 0; i < m; ++i) {
        int x, y, l; cin >> x >> y >> l;
        f.add_edge(x + n, y, l, 1);
        f.add_edge(y + n, x, l, 1);
    }

    f.add_edge(s, a, 0, 1);
    f.add_edge(s, b, 0, 1);
    f.add_edge(c + n, t, 0, 2);

    ii ans = f.max_flow();
    if(ans.se < 2) {
        cout << -1 << endl;
    } else {
        int cost = ans.fi;
        vector<int> path1, path2;
        dfs(f, a, c, n, path1);
        dfs(f, b, c, n, path2);
        reverse(path2.begin(), path2.end());

        path1.pb(c);
        for(int x : path2) path1.pb(x);

        cout << (int)path1.size()-1 << ' ';
        cout << cost << endl;
        for(int x : path1) cout << x << " ";
        cout << endl;
    }
}