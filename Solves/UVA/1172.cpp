#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAXN = 1002;

vector<pair<int, ll> > edges[MAXN];
pli pos[MAXN], memo[MAXN][MAXN];
int n1, n2;

pli solve(int i, int j) {
	if (i > n1) return make_pair(0, 0);
	pli& ret = memo[i][j];
	if (ret.first != -1) return ret;

	int u = pos[i].second;
	int k = lower_bound(edges[u].begin(), edges[u].end(), make_pair(j, -1ll)) - edges[u].begin();

	for (; k < (int)edges[u].size(); k++) {
		pli cur = solve(i+1, edges[u][k].first + 1);
		cur.first += edges[u][k].second + pos[i].first;
		cur.second++;

		if (cur.first > ret.first) ret = cur;
		else if (cur.first == ret.first && cur.second < ret.second) ret = cur;
	}

	pli cur = solve(i+1, j);
	if (cur.first > ret.first) ret = cur;
	else if (cur.first == ret.first && cur.second < ret.second) ret = cur;

	return ret;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n1);

		int cur = 0;
		map<string, int> SO;

		char aux[20];
		for (int i = 1; i <= n1; i++) {
			scanf(" %*s %s %lld", aux, &pos[i].first);
			if (!SO.count(string(aux))) SO[string(aux)] = ++cur;
			pos[i].second = SO[string(aux)];
		}

		scanf("%d", &n2);
		for (int i = 1; i <= n2; i++) {
			ll x; scanf(" %*s %s %lld", aux, &x);
			if (!SO.count(string(aux))) continue;

			edges[SO[string(aux)]].emplace_back(i, x);
		}

		for (int i = 1; i <= n1; i++) for (int j = 0; j <= n2 + 1; j++) memo[i][j] = make_pair(-1ll, 0);
		pli ans = solve(1, 0);
		printf("%lld %d\n", ans.first, ans.second);

		if (t)
		for (int i = 1; i <= cur; i++) edges[i].clear();
	}
}