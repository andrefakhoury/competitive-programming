#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const maxn = 101010;

struct Edge {
    int u, w;
};

vector<Edge> v[maxn];
int t[maxn];
int vis[maxn];
int sz[maxn];

int tam(int x, int p) {
    sz[x] = 1;
    for (Edge e : v[x]) {
        if (e.u == p or vis[e.u]) continue;

        sz[x] += tam(e.u, x);
    }
    return sz[x];
}

int centroid(int x, int p, int tot) {
    for (Edge e : v[x]) {
        if (e.u == p or vis[e.u]) continue;
        if (sz[e.u] > tot/2) return centroid(e.u, x, tot);
    }
    return x;
}

int centroid(int x) {
    int tot = tam(x, x);
    return centroid(x, x, tot);
}

ll cnt;
ll sum_t, sum_dist, ans;

void add(int x, int p, ll dist) {
    sum_t += t[x];
    ans += dist*t[x];
    sum_dist += dist;
    cnt++;

    for (Edge e : v[x]) {
        if (e.u == p or vis[e.u]) continue;
        add(e.u, x, dist + e.w);
    }
}

void rem(int x, int p, ll dist) {
    sum_t -= t[x];
    ans -= dist*t[x];
    sum_dist -= dist;
    cnt--;

    for (Edge e : v[x]) {
        if (e.u == p or vis[e.u]) continue;
        rem(e.u, x, dist + e.w);
    }
}

ll res[maxn];

void calc(int x, int p, ll dist) {
    res[x] += ans + sum_t*dist + sum_dist*t[x];
    for (Edge e : v[x]) {
        if (e.u == p or vis[e.u]) continue;
        sum_dist += cnt*e.w;
        calc(e.u, x, dist + e.w);
        sum_dist -= cnt*e.w;
    }
}

void solve(int x) {
    x = centroid(x);
    vis[x] = 1;
    sum_t = t[x], sum_dist = 0, ans = 0;
    cnt = 1;

    for (Edge e : v[x]) {
        if (vis[e.u]) continue;
        add(e.u, x, e.w);
    }

    res[x] += ans + sum_dist*t[x];

    for (Edge e : v[x]) {
        if (vis[e.u]) continue;
        rem(e.u, x, e.w);
        sum_dist += cnt*e.w;
        calc(e.u, x, e.w);
        sum_dist -= cnt*e.w;
        add(e.u, x, e.w);
    }

    for (Edge e : v[x]) {
        if (vis[e.u]) continue;
        solve(e.u);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        v[a].push_back(Edge{b, w});
        v[b].push_back(Edge{a, w});
    }

    solve(1);
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << "\n";
}