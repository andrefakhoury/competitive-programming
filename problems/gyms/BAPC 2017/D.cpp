#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, int>;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

int const maxn = 101010;
ll const inf = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int u, w;
};

int n;
vector<Edge> v[maxn];
int p[maxn];

void sssp1() {
    vector<ll> dist(n, inf);
    vector<int> vis(n);
    dist[1] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        ll d;
        int at;
        tie(d, at) = pq.top();
        pq.pop();

        if (vis[at]) continue;

        vis[at] = 1;

        for (auto ed : v[at]) {
            if (d + ed.w < dist[ed.u]) {
                p[ed.u] = at;
                dist[ed.u] = d + ed.w;
                pq.emplace(dist[ed.u], ed.u);
            }
        }
    }
}

int p2[maxn];

bool sssp2() {
    vector<ll> dist(n, inf);
    vector<int> vis(n);
    dist[0] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        ll d;
        int at;
        tie(d, at) = pq.top();
        pq.pop();

        if (vis[at]) continue;

        vis[at] = 1;

        for (auto ed : v[at]) {
            if (p[at] == ed.u) continue;

            if (d + ed.w < dist[ed.u]) {
                p2[ed.u] = at;
                dist[ed.u] = d + ed.w;
                pq.emplace(dist[ed.u], ed.u);
            }
        }
    }
    return dist[1] != inf;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        v[a].push_back(Edge{b, w});
        v[b].push_back(Edge{a, w});
    }

    sssp1();
    
    if (sssp2()) {
        vector<int> res{{1}};

        cerr << "ok\n";
        int x = 1;
        while (x != 0) {
            x = p2[x];
            res.push_back(x);
        }

        cout << res.size() << " ";
        reverse(res.begin(), res.end());
        for (int u : res) cout << u << " ";
        cout << "\n";
    }
    else {
        cout << "impossible\n";
    }
}
