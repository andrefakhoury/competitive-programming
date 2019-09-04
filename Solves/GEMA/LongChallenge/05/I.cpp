#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 5;

int n, m;
map<int, bool> vis;
map<int, string> memo;
map<int, char> s;
map<int, vector<int> > edges;

string solve(int u, int T) {
	if (u <= 0 || u > n) return "A";

	if (vis[u]) return memo[u];
	vis[u] = true;

	if (u == T) return memo[u] = s[u];
	if (memo[u] != "A") return memo[u];

	string ret;
	for (int v : edges[u]) {
		string cur = solve(v, T);

		if (cur != "A") {
			if (ret.empty()) ret = s[u] + cur;
			else ret = min(ret, s[u] + cur);
		}
	}

	return memo[u] = ret.empty() ? string("A") : ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		char c; scanf(" %c", &c);
		s[i] = c;
		memo[i] = "A";
	}

	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);

		assert(u > 0 && v > 0 && u <= n && v <= n);
	}

	int a, b; scanf("%d%d", &a, &b);
	string ans = solve(a, b);

	printf("%s\n", ans == "A" || ans.empty() ? "No way" : ans.c_str());
}