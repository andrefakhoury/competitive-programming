#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int u, vector<bool>& vis, vector<vector<int> >& edges) {
	vis[u] = true;
	for (int v : edges[u])
		if (!vis[v]) dfs(v, vis, edges);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	char m; cin >> m;

	while(t--) {
		int n = m - 'A';
		vector<vector<int> > edges(n + 1);

		string s;
		while(cin >> s) {
			if (s.size() == 1) {
				m = s[0];
				break;
			}

			int u = s[0] - 'A';
			int v = s[1] - 'A';

			edges[u].push_back(v);
			edges[v].push_back(u);
		}


		vector<bool> vis(n + 1, false);
		int ans = 0;
		for (int u = 0; u <= n; u++) {
			if (!vis[u]) {
				ans++;
				dfs(u, vis, edges);
			}
		}

		cout << ans;
		if (t) cout << "\n\n";
		else cout << "\n";
	}
}