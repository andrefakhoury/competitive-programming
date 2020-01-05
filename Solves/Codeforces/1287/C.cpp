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
const int MAXN = 100 + 1;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN], n;
int memo[MAXN][MAXN][MAXN][10];

int solve(int i, int par, int imp, int prev) {
	if (i > n) return 0;

	int& ret = memo[i][par][imp][prev];
	if (~ret) return ret;

	int cur = INT_MAX;
	if (a[i] == 0) {
		if (par) {
			if (prev == 0) cur = min(cur, solve(i+1, par-1, imp, 2));
			else cur = min(cur, (prev%2 != 0) + solve(i+1, par-1, imp, 2));
		}
		if (imp) {
			if (prev == 0) cur = min(cur, solve(i+1, par, imp-1, 1));
			else cur = min(cur, (prev%2 != 1) + solve(i+1, par, imp-1, 1));
		}
	} else {
		if (prev == 0) cur = min(cur, solve(i+1, par, imp, a[i]%2 == 0 ? 2 : 1));
		else cur = min(cur, (prev%2 != a[i]%2) + solve(i+1, par, imp, a[i]%2 == 0 ? 2 : 1));
	}

	return ret = cur;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	memset(memo, -1, sizeof memo);

	cin >> n;

	set<int> st;
	for (int i = 1; i <= n; i++) st.emplace(i);

	int par = 0, impar = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st.erase(a[i]);
	}

	for (int x : st) {
		par += x%2 == 0;
		impar += x%2 == 1;
	}

	cout << solve(1, par, impar, 0) << '\n';

	return 0;
}