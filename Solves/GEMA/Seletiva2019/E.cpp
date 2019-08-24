#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back

typedef long long ll;

const int MAXN = 1e6 + 5;

vector<int> a[MAXN];
ll memo[MAXN];
int n, N, k = 3;

ll solve(int c) {
	if (c > N) return 0;

	cout << c << endl;

	ll& ret = memo[c];
	if (~ret) return ret;

	for (int i = 0; i < min((int)a[c+1].size(), k); i++) {
		ll cur = max(abs(a[c+1][i] - a[c].front()), abs(a[c+1][i] - a[c].back()));
		ret = max(ret, cur + solve(c+1));
	}

	for (int i = a[c+1].size() - 1; i >= max(0, (int)a[c+1].size() - k); i--) {
		ll cur = max(abs(a[c+1][i] - a[c].front()), abs(a[c+1][i] - a[c].back()));
		ret = max(ret, cur + solve(c+1));
	}

	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);

	scanf("%d", &n);

	set<int> all;
	vector<pair<int, int> > inp;

	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		inp.eb(x, y);
		all.insert(x);
	}

	map<int, int> mp;
	for (int x : all) mp[x] = ++N;

	for (auto p : inp) a[mp[p.first]].pb(p.second);
	for (int i = 1; i <= N; i++) sort(a[i].begin(), a[i].end());

	cout << solve(1) << endl;



}