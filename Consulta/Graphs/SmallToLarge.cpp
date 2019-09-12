    #include <bits/stdc++.h>
     
    using namespace std;
     
    int const maxn = 101010;
     
    namespace Bit {
        int v[maxn];
     
        void add(int pos, int val) {
            pos++;
            for (int i = pos; i < maxn; i += i&-i)
                v[i] += val;
        }
     
        int get(int pos) {
            pos++;
            int ans = 0;
            for (int i = pos; i > 0; i -= i&-i)
                ans += v[i];
            return ans;
        }
    }
     
    struct Query {
        int k, id;
    };
     
    int t = 0;
    vector<int> v[maxn];
    vector<Query> qr[maxn];
    int ft[maxn], lt[maxn], cor[maxn], freq[maxn], ans[maxn], sz[maxn];
    int pos[maxn];
     
    int dfs(int x, int p = -1) {
        sz[x] = 1;
        ft[x] = ++t;
        pos[t] = x;
     
        for (int u : v[x]) {
            if (u != p) sz[x] += dfs(u, x);
        }
     
        lt[x] = t;
     
        return sz[x];
    }
     
    void add_vertex(int x, int qt) {
        if (freq[cor[x]]) Bit::add(freq[cor[x]], -1);
        freq[cor[x]] += qt;
        if (freq[cor[x]]) Bit::add(freq[cor[x]],  1);
    }
     
    void solve(int x, int p = -1, bool heavy = false) {
        int maior = -1, idx = -1;
     
        for (int u : v[x]) {
            if (u == p) continue;
            if (sz[u] > maior) {
                maior = sz[u], idx = u;
            }
        }
     
        for (int u : v[x]) {
            if (u == p or u == idx) continue;
            solve(u, x);
        }
     
        if (idx != -1) {
            solve(idx, x, true);
        }
     
        add_vertex(x, 1);
     
        for (int u : v[x]) {
            if (u == p or u == idx) continue;
            for (int i = ft[u]; i <= lt[u]; i++) {
                add_vertex(pos[i], 1);
            }
        }
     
        for (Query& qr : qr[x]) {
            ans[qr.id] = Bit::get(maxn-2) - Bit::get(qr.k-1);
        }
     
        if (!heavy) {
            for (int i = ft[x]; i <= lt[x]; i++) {
                add_vertex(pos[i], -1);
            }
        }
    }
     
    int main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
     
        int n, q;
        cin >> n >> q;
     
        for (int i = 1; i <= n; i++) cin >> cor[i];
     
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
     
        for (int i = 0; i < q; i++) {
            int x, k;
            cin >> x >> k;
            qr[x].push_back(Query{k, i});
        }
     
        dfs(1);
     
        solve(1, 1, true);
     
        for (int i = 0; i < q; i++) cout << ans[i] << "\n";
     
    }
