#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 200;

vector<int> edges[MAXN];
int a[MAXN];

double ans = 0;

pii dfs(int u) {

    pii ret = mp(1, a[u]);

    for (int v : edges[u]) {
        pii cur = dfs(v);
        ret.fi += cur.fi;
        ret.se += cur.se;
    }

    ans = max(ans, ret.se / (double)ret.fi);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (x) edges[x].pb(i);
        a[i] = y;
    }

    dfs(1);

    cout << fixed << setprecision(3) << ans << endl;

    return 0;
}