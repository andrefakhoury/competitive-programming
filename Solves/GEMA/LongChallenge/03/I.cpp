#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;

vector<int> edges[MAXN];

int color[MAXN];
vector<int> sameColor[MAXN];

void dfs(int u, int c) {
	sameColor[c].pb(u);
	color[u] = c;

	for (int v : edges[u]) {
		if (!color[v]) dfs(v, c);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	
	while(t--) {
		string s; cin >> s;
		int m, n = s.size(); cin >> m;

		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			edges[u].pb(v);
			edges[v].pb(u);
		}

		string ans;
		ans.resize(n);

		int curColor = 0;

		for (int i = 0; i < n; i++) {
			if (!color[i]) dfs(i, ++curColor);
		}

		for (int c = 1; c <= curColor; c++) {
			string cur;
			for (int i : sameColor[c]) cur += s[i];
			sort(cur.begin(), cur.end());
			sort(sameColor[c].begin(), sameColor[c].end());

			for (int i = 0; i < (int)sameColor[c].size(); i++) {
				ans[sameColor[c][i]] = cur[i];
			}
		}

		cout << ans << '\n';

		for (int i = 0; i < MAXN; i++) edges[i].clear();
		for (int i = 0; i < MAXN; i++) sameColor[i].clear();
		memset(color, 0, sizeof color);
	}
}