#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

ll const inf = 0x3f3f3f3f3f3f3f3f;
int const maxn = 505;

int const flow_inf = 100000;

template<typename edge>
struct Dinic {

    struct FlowEdge {
        int v, u;
        edge cap, flow = 0;
        FlowEdge(int v, int u, edge cap) : v(v), u(u), cap(cap) {};
    };

    vector<FlowEdge> edges;
    vector<vector<int>> adj;

    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, edge cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);

        adj[v].push_back(m);
        adj[u].push_back(m+1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow <= 0) {
                    continue;
                }
                if (level[edges[id].u] != -1) {
                    continue;
                }
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    edge dfs(int v, edge pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;

            if (level[v] + 1 != level[u] or edges[id].cap - edges[id].flow <= 0)
                continue;
            edge tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id^1].flow -= tr;
            return tr;
        }
        return 0;
    }

    edge flow() {
        edge f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (edge pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int n, m, ans;
string w[maxn];
 
vector<int> adj[maxn];

int vis[maxn];

void dfs(int x, int cor) {
    vis[x] = 2-cor;

    for (int u : adj[x]) {
        if (vis[u]) continue;
        dfs(u, cor^1);
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>w[i];
    m = w[0].size();

    Dinic<int> f(n+2, n, n+1);
  
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                int cont=0;
                for(int k=0; k<m; k++){
                    if(w[i][k]!=w[j][k])
                        cont++;
                }
                if(cont==2){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if (vis[i] == 0) dfs(i, 0);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] == 1) {
            f.add_edge(n, i, 1);
            for (int u : adj[i]) {
                f.add_edge(i, u, flow_inf);
            }
        }
        else {
            f.add_edge(i, n+1, 1);
        }
    }

    cout << n-f.flow() << "\n";
  
    return 0;
}
