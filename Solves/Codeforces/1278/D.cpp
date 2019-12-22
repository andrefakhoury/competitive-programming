#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
const int MAXN = 5e5 + 5;

vector<int> edges[MAXN];
bool vis[MAXN];

bool dfs(int u, int p) {
	vis[u] = true;

	bool ret = true;
	for (int v : edges[u]) {
		if (!vis[v]) ret &= dfs(v, u);
		else if (v != p) return false;
	}

	return ret;
}

bool isTree(int n, int m) {
	if (m != n-1) return false;
	bool ans = dfs(1, 1);
	for (int i = 1; i <= n; i++) ans &= vis[i];
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<pii> a(n);
	for (auto& p : a) cin >> p.fi >> p.se;
	sort(a.begin(), a.end());

	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n && m < n; j++) {
			if (a[j].fi > a[i].se) break;
			if (a[j].se <= a[i].se) continue;

			edges[i+1].eb(j+1);
			edges[j+1].eb(i+1);
			m++;
		}
	}

	cout << (isTree(n, m) ? "YES" : "NO") << '\n';
}