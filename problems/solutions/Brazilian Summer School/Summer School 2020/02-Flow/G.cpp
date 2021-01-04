#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define debug false
#define int long long
#define eb emplace_back
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f3f3f3f3fll;

struct MCMF {
    struct Edge {
        int to, cost, cap, flow, rid;

        Edge(){}

        Edge(int a, int b, int c, int d, int e) :  
            to(a), cost(b), cap(c), flow(d), rid(e) {}
        
    };
    vector<vector<Edge> > edges;
    vector<int> h, dist;
    vector<ii> par;

    int n, s, t;

    MCMF(int n, int s, int t) : n(n), s(s), t(t) {
        edges.resize(n+1);
        h.resize(n+1);
        dist.resize(n+1);
        par.resize(n+1);
    }

    void add_edge(int u, int v, int cost, int cap) {
        edges[u].eb(v, cost, cap, 0, edges[v].size());
        edges[v].eb(u, -cost, 0, 0, (int) edges[u].size() - 1);
    }

    void bellman_ford(int s) {
        fill(h.begin(), h.end(), INF);
        h[s] = 0;

        for(int i = 0; i < n - 1; i++) {
            for(int at = 0; at < n; ++at) {
                for(int j = 0; j < (int) edges[at].size(); ++j) {
                    if(!edges[at][j].cap) continue;
                    int next = edges[at][j].to, w = edges[at][j].cost;
                    h[next] = min(h[next], h[at]+w);
                }
            }
        }
    }

    bool dijkstra(int s, int t) {
        fill(dist.begin(), dist.end(), INF);
        fill(par.begin(), par.end(), ii(-1, -1));

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
                if(edg.cap - edg.flow <= 0) continue;

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

    ii max_flow() {
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

const int N = 107;

int32_t main() {

    int n, m; cin >> n >> m;

    int s = 1, t = n;
    MCMF f(N, s, t);
    for(int i = 0; i < m; ++i) {
        int u, v, cost, cap; cin >> u >> v >> cap >> cost;
        f.add_edge(u, v, cost, cap);
    }

    ii ans = f.max_flow();
    cout << ans.fi << endl;

}
    