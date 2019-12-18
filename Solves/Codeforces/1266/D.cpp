#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 3e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<tuple<int, int, ll> > ans;
ll deb[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w; cin >> u >> v >> w;
		deb[u] += w;
		deb[v] -= w;
	}

	priority_queue<pair<ll, int> > pos, neg;
	for (int i = 1; i <= n; i++) {
		if (deb[i] > 0) pos.emplace(deb[i], i);
		if (deb[i] < 0) neg.emplace(deb[i], i);
	}

	while(pos.size() && neg.size()) {
		int u = pos.top().se, v = neg.top().se;
		pos.pop();
		neg.pop();

		ll z = min(deb[u], -deb[v]);
		deb[u] -= z, deb[v] += z;
		ans.eb(u, v, z);

		if (deb[u]) pos.emplace(deb[u], u);
		if (deb[v]) neg.emplace(deb[v], v);
	}

	cout << ans.size() << '\n';
	for (auto p : ans) {
		int u, v; ll w;
		tie(u, v, w) = p;

		cout << u << ' ' << v << ' ' << w << '\n';
	}

	return 0;
}