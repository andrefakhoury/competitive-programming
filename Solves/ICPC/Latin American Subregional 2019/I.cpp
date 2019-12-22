#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 404;

int dist[MAXN][MAXN];
int dist2[MAXN][MAXN];
int ans[MAXN * MAXN];
int n, r;

int S[MAXN][2];
int T[MAXN];

struct Query {
	int u, v, k, id;
	Query() {}
	Query(int a, int b, int c, int d) {
		u = a, v = b, k = c, id = d;
	}

	bool operator<(Query const& p) const {
		return k < p.k;
	}
};

void f(vector<pii>& ver, vector<Query>& qry, int AA) {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			dist2[i][j] = dist[i][j] == 0 ? 0x3f3f3f3f : dist[i][j];
		}
		dist2[i][i] = 0;
	}

	int q = 0;
	for (int ind = 0; ind < (int)ver.size(); ind++) {
		int k = ver[ind].se;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
			}
		}

		if (ind == (int)ver.size() - 1 || S[ver[ind].se][AA] != S[ver[ind+1].se][AA]) {
			int KK = S[ver[ind].se][AA];

			while(q < (int)qry.size() && qry[q].k == KK) {
				ans[qry[q].id] = dist2[qry[q].u][qry[q].v];
				ans[qry[q].id] = ans[qry[q].id] == 0x3f3f3f3f ? -1 : ans[qry[q].id];
				q++;
			}
		}
	}
	while(q < (int)qry.size()) {
		ans[qry[q].id] = dist2[qry[q].u][qry[q].v];
		ans[qry[q].id] = ans[qry[q].id] == 0x3f3f3f3f ? -1 : ans[qry[q].id];
		q++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> r;

	vector<pii> temp;
	vector<int> all;

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		temp.eb(x, i);
		all.pb(x);
		T[i] = x;
	}

	sort(temp.begin(), temp.end());
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	for (int i = 1; i <= n; i++) {
		S[i][0] = lower_bound(all.begin(), all.end(), T[i]) - all.begin() + 1;
		S[i][1] = all.size() - S[i][0] + 1;
	}

	for (int i = 1; i <= r; i++) {
		int u, v, w; cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}

	int q; cin >> q;
	vector<Query> sm, la;
	for (int i = 0; i < q; i++) {
		int a, b, k, t; cin >> a >> b >> k >> t;
		if (t == 0) {
			sm.eb(a, b, k, i);
		} else {
			la.eb(a, b, k, i);
		}
	}

	sort(sm.begin(), sm.end());
	sort(la.begin(), la.end());

	f(temp, sm, 0);
	reverse(temp.begin(), temp.end());
	f(temp, la, 1);

	for (int i = 0; i < q; i++) cout << ans[i] << '\n';


	return 0;
}