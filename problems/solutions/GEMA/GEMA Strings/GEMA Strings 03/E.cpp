#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pii;

const int MOD[2] = {1000000007, 1000000009};
const int P = 37;
const int MAXN = 2e5 + 5;
const int invPow1 = 621621626;
const int invPow2 = 297297300;

int curPow[2][MAXN];

pii A[127], B[127];
int s[MAXN], t[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	freopen("substring.in", "r+", stdin);
	freopen("substring.out", "w", stdout);

	string x, y; cin >> x >> y;

	int N = x.size() + 1, M = y.size() + 1;
	for (int i = 1; i < N; i++) s[i] = x[i-1];
	for (int i = 1; i < M; i++) t[i] = y[i-1];

	curPow[0][0] = curPow[1][0] = 1;

	for (int i = 1; i < MAXN; i++) for (int k = 0; k < 2; k++)
		curPow[k][i] = (curPow[k][i-1] * ll(P)) % MOD[k];

	for (int i = 1; i < M; i++) {
		A[t[i]].fi = (A[t[i]].fi + ll(curPow[0][i]));
		if (A[t[i]].fi >= MOD[0]) A[t[i]].fi -= MOD[0];
		A[t[i]].se = (A[t[i]].se + ll(curPow[1][i]));
		if (A[t[i]].se >= MOD[1]) A[t[i]].se -= MOD[1];
	}

	vector<pii> used;
	for (int i = 33; i <= 126; i++) if (A[i].fi || A[i].se) used.emplace_back(A[i]);
	sort(used.begin(), used.end());

	set<pii> C;

	unordered_set<int> current;
	for (int i = 1; i < M; i++) {
		B[s[i]].fi = (B[s[i]].fi + ll(curPow[0][i]));
		if (B[s[i]].fi >= MOD[0]) B[s[i]].fi -= MOD[0];
		B[s[i]].se = (B[s[i]].se + ll(curPow[1][i]));
		if (B[s[i]].se >= MOD[1]) B[s[i]].se -= MOD[1];

		current.insert(s[i]);
	}

	for (int i = 33; i <= 126; i++) C.insert(B[i]);

	bool ok = true;
	for (auto pp : used) ok &= C.find(pp) != C.end();

	vector<int> ans;
	if (ok) ans.emplace_back(1);

	vector<pii> actual;
	for (int i = M; i < N; i++) {
		actual.clear();

		B[s[i - M + 1]].fi = ((B[s[i - M + 1]].fi - ll(P) + MOD[0]));
		if (B[s[i - M + 1]].fi >= MOD[0]) B[s[i - M + 1]].fi -= MOD[0];
		B[s[i - M + 1]].se = ((B[s[i - M + 1]].se - ll(P) + MOD[1]));
		if (B[s[i - M + 1]].se >= MOD[1]) B[s[i - M + 1]].se -= MOD[1];

		// C.clear();
		if (B[s[i - M + 1]].fi == 0 && B[s[i - M + 1]].se == 0) current.erase(s[i - M + 1]);

		// divide
		for (int j : current) {
			B[j].fi = (B[j].fi * ll(invPow1)) % MOD[0];
			B[j].se = (B[j].se * ll(invPow2)) % MOD[1];
			if (j != s[i]) actual.emplace_back(B[j]);
		}

		// add
		B[s[i]].fi = (B[s[i]].fi + ll(curPow[0][M-1]));
		if (B[s[i]].fi >= MOD[0]) B[s[i]].fi -= MOD[0];
		B[s[i]].se = (B[s[i]].se + ll(curPow[1][M-1])) % MOD[1];
		if (B[s[i]].se >= MOD[1]) B[s[i]].se -= MOD[1];

		actual.emplace_back(B[s[i]]);
		sort(actual.begin(), actual.end());
		current.insert(s[i]);

		if (current.size() != used.size()) continue;

		bool ok = true;
		for (int i = 0; ok && i < (int)used.size(); i++)
			ok &= actual[i] == used[i];

		if (ok) ans.emplace_back(i - M + 2);
	}

	cout << ans.size() << '\n';
	for (int x : ans) cout << x << ' ';
	cout << '\n';
}