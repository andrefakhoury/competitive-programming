#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 120005;

// pair<int, int> a[MAXN];
int a[MAXN];
vector<ll> mincost;

pair<int, ll> solve(int k, int n, int s) {
	ll cost = 0;
	int i, j;

	mincost.clear();
	for (int i = 1; i <= n; i++)
		mincost.push_back(a[i] + 1LL * i * k);

	sort(mincost.begin(), mincost.end());

	for (i = 0, j = 1; i < k && j; i++) {
		if (cost + mincost[i] > s) j = 0;
		cost += mincost[i];
	}

	return cost <= s ? make_pair(i, cost) : make_pair(-1, LLONG_MAX);
}

int main() {
	int n, s; scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	pair<int, ll> ans = make_pair(0, 0);
	int lo = 0, hi = n, mi;
	while(lo <= hi) {
		mi = (lo+hi)/2;

		pair<int, ll> cur = solve(mi, n, s);

		if (cur.first > ans.first) {
			ans = cur;
			lo = mi + 1;
		} else if (cur.first == ans.first) {
			ans.second = min(ans.second, cur.second);
			lo = mi + 1;
		} else {
			hi = mi - 1;
		}
	}

	printf("%d %lld\n", ans.first, ans.second);
	return 0;
}