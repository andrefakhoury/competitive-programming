#include <bits/stdc++.h>

using namespace std;

int const maxn = 101010;

struct Seq {
    Seq() = default;

    void _add(int x) {
        n = 1;
        ans = 1;
        x0 = x;
        c[0] = 1;
        ci[0] = 1;
    }

    void add(int x) {
        if (n == 0) {
            _add(x);
            return;
        }

        x -= x0;
        int xx = x-n, xi = x+n;
        n++;
        c[xx]++, ci[xi]++;
        ans = max({ans, c[xx], ci[xi]});
    }

    int get() {
        return n-ans;
    }

    void clear() {
        n = 0;
        c.clear();
        ci.clear();
    }

private:
    int n, ans, x0;
    map<int, int> c, ci;
};

struct Query {
    int l, r, id;

    bool operator<(Query const& rhs) const {
        return tie(l, r) < tie(rhs.l, rhs.r);
    }
};

vector<int> v[maxn];
int a[maxn];

int root[maxn], p[maxn];

bool dfs(int x, int par) {
    p[x] = par;
    bool ok = true;
    int cnt = 0;

    for (int u : v[x]) {
        if (u == par) continue;

        if (!dfs(u, x)) ok = false;

        cnt++;
    }

    if (ok and cnt <= 2) {
        root[x] = 1;
        for (int u : v[x]) {
            if (u == par) continue;
            root[u] = 0;
        }
    }

    if (cnt >= 2 or !ok) return false;

    return true;
}

bool is_2(int x) {
    int cnt = 0;
    for (int u : v[x]) {
        if (u == p[x]) continue;
        cnt++;
    }
    return cnt == 2;
}

int res[maxn];
Seq s;

void add_all(int x, int par, bool inv) {
    if (!inv) {
        for (int u : v[x]) {
            if (u == par) continue;
            add_all(u, x, inv);
        }
        s.add(a[x]);
    }
    else {
        s.add(a[x]);
        for  (int u : v[x]) {
            if (u == par) continue;
            add_all(u, x, inv);
        }
    }
}

void dfs2(int x, int par) {
    if (is_2(x)) {
        s.clear();
        bool inv = false;
        for (int u : v[x]) {
            if (u == par) continue;
            add_all(u, x, inv);
            if (!inv) s.add(a[x]);
            inv = true;
        }
        res[x] = s.get();

        for (int u : v[x]) {
            if (u == par) continue;
            s.clear();
            dfs2(u, x);
        }
    }
    else {
        for (int u : v[x]) {
            if (u == par) continue;
            dfs2(u, x);
        }
        s.add(a[x]);
        res[x] = s.get();
    }
}

void clean(int n) {
    for (int i = 1; i <= n; i++) {
        v[i].clear();
        root[i] = 0;
        p[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 0; i < n-1; i++) {
            int x, y;
            cin >>x  >> y;

            v[x].push_back(y);
            v[y].push_back(x);
        }

        dfs(1, 1);

        fill(res+1, res+n+1, -1);
        for (int i = 1; i <= n; i++) {
            if (root[i]) {
                s.clear();
                dfs2(i, p[i]);
            }
        }

        for (int i = 1; i <= n; i++) cout << res[i] << " ";
        cout << "\n";
        clean(n);
    }
}