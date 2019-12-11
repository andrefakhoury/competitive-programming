#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

typedef long long ll;

const int MAXN = 1e6 + 5;

vector<int> a[MAXN], b[MAXN];
int N, n;

int solve(int c) {
	
}

int main() {
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

	for (auto p : inp) b[mp[p.fi]].pb(p.se);
	for (int i = 1; i <= N; i++) sort(b[i].begin(), b[i].end());
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)b[i].size(); j++) {
			if (j < 5 || j > (int)b[i].size() - 5) a[i].eb(b[i][j]);
		}
	}

	cout << solve(1) << '\n';
}