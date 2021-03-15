#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 200007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ii> e[N], rev[N];
int vis[N];
bool inside[N];
ii edges[N];

int tt;
int sem = 0;

void dfs(int u) {
	vis[u] = 1;
	for(auto & [v, i] : e[u]) {
		if(vis[v] == 0) {
			inside[i] = true;
			dfs(v);
		}
	}
}
void dfs2(int u) {
	vis[u] = 1;
	for(auto & [v, i] : rev[u]) {
		if(vis[v] == 0) {
			inside[i] = true;
			dfs2(v);
		}
	}
}

void _solve() {
	int n, m; cin >> n >> m;

	tt = sem = 1;
	for(int i = 1; i <= n; i++) {
		e[i].clear();
		rev[i].clear();
		vis[i] = 0;
	}

	for(int i = 0; i < m; i++) {
		inside[i] = false;
		int u, v; cin >> u >> v;
		edges[i] = ii(u, v);
		e[u].eb(v, i);
		rev[v].eb(u, i);
	}

	dfs(1);
	for(int i = 1; i <= n; ++i) vis[i] = 0;
	dfs2(1);

	int cnt = 2 * n;
	vector<ii> ans;
	for(int i = 0; i < m; i++) {
		if(inside[i]) cnt--;
	}

	for(int i = 0; i < m; ++i) {
		if(!inside[i]) {
			if(cnt) {
				cnt--;
			} else ans.pb(edges[i]);
		}
	}

	for(auto & [u, v] : ans) cout << u << ' ' << v << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--) _solve();
}