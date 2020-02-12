#include <bits/stdc++.h>
using namespace std;
 #define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int maxn = 110;
const int inf = 0x3f3f3f3f3f3f3f3f;
 int n, m, k;
 struct Edge {
    int u, w;
};
 vector<Edge> v[maxn];
 struct Distance {
    int recharges, energy;
     Distance(int re, int en) : recharges(re), energy(en) {};
     Distance() = default;
     bool operator>(Distance const& rhs) const {
        if (recharges != rhs.recharges) return recharges > rhs.recharges;
        return energy < rhs.energy;
    }
     bool operator<(Distance const& rhs) const {
        if (recharges != rhs.recharges) return recharges < rhs.recharges;
        return energy > rhs.energy;
    }
};
 struct Vertex : public Distance {
    int at;
     Vertex(int at, int r, int en) : Distance(r, en), at(at) {};
     Vertex() = default;
};
 Distance dist[maxn];
 bool possible(int root, int max_energy) {
    priority_queue<Vertex, vector<Vertex>, greater<Vertex> > pq;
    pq.emplace(root, 1, max_energy);
     fill(dist, dist+maxn, Distance(inf, 0));
    dist[root] = Distance(1, max_energy);
     while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
         if (dist[x.at] < x) continue;
         for (Edge const& e : v[x.at]) {
            if (e.w > max_energy) continue;
             Distance d = x;
            d.energy -= e.w;
            if (d.energy < 0) {
                d.recharges++;
                d.energy = max_energy-e.w;
            }
             if (d < dist[e.u]) {
                dist[e.u] = d;
                pq.emplace(e.u, d.recharges, d.energy);
            }
        }
    }
     for (int i = 0; i < n; i++) {
        if (dist[i].recharges > k) return false;
    }
     return true;
}
 bool test(int max_energy) {
    for (int i = 0; i < n; i++) {
        if (!possible(i, max_energy)) return false;
    }
    return true;
}
 void clean() {
    for (auto& i : v) i.clear(); 
}
 decltype(1) main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     int t;
    cin >> t;
     while (t--) {
        clean();
         cin >> n >> k >> m;
         for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
             v[a].push_back(Edge{b, w});
            v[b].push_back(Edge{a, w});
        }
         int l = 0, r = inf;
         while (r-l > 1) {
            int m = (l+r+1)/2;
             if (test(m)) r = m;
            else l = m;
        }
        cout << r << "\n";
    }
     return 0;
}