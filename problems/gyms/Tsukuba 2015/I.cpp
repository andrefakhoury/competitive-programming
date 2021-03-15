#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const maxn = 40;
int const inf = 0x3f3f3f3f;

int n, ans = inf;
vector<int> v[maxn];
int c[maxn];

bitset<40> vis, inv[maxn];

void solve(int x, bitset<40> mask, int until = 0) {
    int cost = 0;
    for (int u : v[x]) {
        if (!mask[u]) cost += c[u];
        mask[u] = 1;
    }

    if (!mask[x]) cost += c[x];
    mask[x] = 1;

    if (until + cost >= ans) {
        return;
    }

    if (x == n-1) {
        ans = min(ans, until + cost);
        return;
    }

    if ((inv[x]&vis).count() > 1) return;

    for (int u : v[x]) {
        if (vis[u]) continue;

        vis[u] = 1;

        solve(u, mask, until + cost);

        vis[u] = 0;
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--, b--;

        v[a].push_back(b);
        v[b].push_back(a);

        inv[a][b] = 1;
        inv[b][a] = 1;
    }
    mt19937 rd{51};

    for (int i = 0; i < n; i++) {
        shuffle(v[i].begin(), v[i].end(), rd);
    }

    solve(0, {});


    cout << ans << "\n";
}
