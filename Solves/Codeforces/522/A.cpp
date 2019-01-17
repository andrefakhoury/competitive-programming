#include <bits/stdc++.h>
using namespace std;

map<string, set<string> > edges;

void strlower(string& a) {
	for (int i = 0; i < a.size(); i++)
		a[i] += a[i] >= "A" && a[i] <= "Z" ? 32 : 0;
}

int dfs(string u) {
	int ret = 0;
	for (string s : edges[u])
		ret = max(ret, dfs(s));
	return ret + 1;
}

int main() {
	int n; cin >> n;
	string a, b, c;

	for (int i = 1; i <= n; i++) {
		cin >> a >> c >> b;
		strlower(a); strlower(b);
		edges[b].insert(a);
	}

	int ans = 0;
	for (auto it = edges.begin(); it != edges.end(); it++)
		ans = max(ans, dfs(it->first));

	cout << ans << endl;
}