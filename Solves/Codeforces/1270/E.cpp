#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pii pt[MAXN];

ll dist(int i, int j) {
	return (pt[i].fi-pt[j].fi)*(pt[i].fi-pt[j].fi) + (pt[i].se-pt[j].se)*(pt[i].se-pt[j].se);
}

vector<int> edges[MAXN];

void add(int u, int v) {
	edges[u].eb(v);
	edges[v].eb(u);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &pt[i].fi, &pt[i].se);

	map<ll, vector<pii> > all;

	for (int i = 1; i <= n; i++) {
		map<ll, vector<int> > mp;
		for (int j = i+1; j <= n; j++) {
			ll d = dist(i, j);
			for (int x : mp[d]) add(j, x);
			mp[d].eb(j);
			all[d].eb(i, j);
		}
	}
}