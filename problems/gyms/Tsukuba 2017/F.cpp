#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;

const int N = 1000007;

tuple<int, int, int> edges[N];

vector<int> e[2][N];
int p[2][N];

vector<int> g[N];
int n, m; 
int id[N];
ll d[2][N];

int other(int u, int ed) {
    int uu, v, c;
    tie(uu, v, c) = edges[ed];
    assert(u == uu or u == v);
    return u == uu? v : uu;
}

void dijkstra(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;

    for(int i = 1; i <= n; ++i) d[s-1][i] = (ll)1e17;
    d[s-1][s] = 0;
    p[s-1][s] = -1;
    pq.emplace(0, s);
    s--;
    
    while(pq.size()) {
        int u;
        ll dist;
        tie(dist, u) = pq.top();
        pq.pop();

        if(dist > d[s][u]) continue;

        for(int ed : e[s][u]) {
            int a, v, w; tie(a, v, w) = edges[ed];
            v = other(u, ed);

            if(d[s][v] > d[s][u] + w) {
                d[s][v] = d[s][u] + w;
                p[s][v] = ed;
                pq.emplace(d[s][v], v);
            }
        }
    }
}
bool inside[N];


int memo[N];
int solve(int u) {
    int & st = memo[u];

    if(st == -1) {
        st = 0;
        for(int v : g[u]) {
            st = max(st, id[v]? id[v] : solve(v));
        }    
    }
    return st;
}

bool critical[N];
map<int, int> cnt[N];

int main() {
    memset(memo, -1, sizeof memo);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges[i] = {u, v, c};
        e[0][u].pb(i);
        e[1][v].pb(i);
    }

    dijkstra(1);
    dijkstra(2);

    // 2 eh a casa da menina
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        tie(u, v, c) = edges[i];
        if(d[0][u] + d[1][v] + c == d[0][2]) { // ele ta no grafo
            g[v].pb(u);
            cnt[u][v]++;
        }
    }

    int pos = 0;
    for(int u = 2; u != 1; u = other(u, p[0][u])) {
        id[other(u, p[0][u])] = ++pos;
        inside[p[0][u]] = true;
    }
    id[1] = ++pos;

    int mai = 0;
    for(int u = 2; u != 1; u = other(u, p[0][u])) {
        int v = other(u, p[0][u]);
        // cout << id[u] << ' ';

        int j = id[other(u, p[0][u])];
        int flag = 0;

        for(int x : g[u]) {
            if(x != v and solve(x) >= j) flag = 1;
        }
        
        if(mai < j and cnt[v][u] == 1 and solve(u) <= j and !flag) {
            critical[p[0][u]] = true;
        }
        mai = max(mai, solve(u));
    }
    // cout << endl;

    ll best = d[0][2];

    for(int i = 0; i < m; ++i) {
        int u, v, c;
        tie(u, v, c) = edges[i];
        if(d[0][v] + c + d[1][u] < best) {
            cout << "HAPPY\n";
        } else {
            // cout << inside[i] << ' ' << critical[i] << ' ' << d[0][v] + c + d[1][u] << endl;
            if(!inside[i] or !critical[i] or d[0][v] + c + d[1][u] == best) {
                cout << "SOSO\n";
            } else {
                cout << "SAD\n";
            }
        }
    }
}