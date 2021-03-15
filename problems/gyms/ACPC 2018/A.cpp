#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int const maxn = 101010;

vector<int> v[maxn];
int sz[maxn], vis[maxn];

int tam(int x, int p) {
    sz[x] = 1;
    for (int u : v[x]) {
        if (u == p or vis[u]) continue;

        sz[x] += tam(u, x);
    }
    return sz[x];
}

int decompose(int x, int p, int tot) {
    for (int u : v[x]) {
        if (u == p or vis[u]) continue;

        if (sz[u] > tot/2) return decompose(u, x, tot);
    }
    return x;
}

int centroid(int x) {
    int tot = tam(x, x);
    return decompose(x, x, tot);
}

int cnt[maxn];

struct Bit {
    Bit() : b(maxn) {};

    void add(int pos, int val) {
        pos++;
        for (int i = pos; i < maxn; i += i&-i) {
            b[i] += val;
        }
    }

    int get(int a, int b) {
        return get(b) - get(a-1);        
    }

private:
    int get(int pos) {
        pos++;
        int res = 0;
        for (int i = pos; i > 0; i -= i&-i) {
            res += b[i];
        }
        return res;
    }

    vector<int> b;
};

Bit bit{};

void add(int x, int p, int d) {
    bit.add(d, 1);
    for (int u : v[x]) {
        if (u == p or vis[u]) continue;

        add(u, x, d+1);
    }
}

void rem(int x, int p, int d) {
    bit.add(d, -1);
    for (int u : v[x]) {
        if (u == p or vis[u]) continue;

        rem(u, x, d+1);
    }
}

ll calc(int x, int p, int d, int a, int b) {
    int l = a-d;
    int r = b-d;

    ll res = bit.get(l, r);

    for (int u : v[x]) {
        if (u == p or vis[u]) continue;

        res += calc(u, x, d+1, a, b);
    }

    return res;
}

ll solve(int x, int a, int b) {
    x = centroid(x);
    vis[x] = 1;

    ll res = 0;

    bit.add(0, 1);
    for (int u : v[x]) {
        if (vis[u]) continue;

        res += calc(u, x, 1, a, b);
        add(u, u, 1);
    }

    // cout << x << "\n";
    // for (int i = 0; i <= 5; i++) cout << bit.get(i, i) << " ";
    // cout << "\n";

    rem(x, x, 0);

    for (int u : v[x]) {
        if (vis[u]) continue;

        res += solve(u, a, b);
    }

    return res;
}

void reset(int n) {
    for (int i = 1; i <= n; i++) v[i].clear();
    fill(vis+1, vis+1+n, 0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    freopen("awesome.in", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        int a = n-1-r;
        int b = n-1-l;

        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;

            v[a].push_back(b);
            v[b].push_back(a);
        }

        ll res = solve(1, a, b);

        cout << res << "\n";

        reset(n);
    }
}