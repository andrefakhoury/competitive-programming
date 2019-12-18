#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<string> a, rev;
set<pair<string, int> > st[2][2];

bool ini(int k, int l, int i) {
	if (i == n-1) return true;
	return st[k][0].size() + st[k][1].size();
}
	
set<int> solve(int l, bool& ok) {
	set<int> ans;
	set<string> used;
	ok = true;
	for (int i = 0; ok && i < n; i++) {

		bool nice = false;
		for (int k = 0; !nice && k < 2; k++) {
			if (st[l][k].size()) {
				pair<string, int> at = *st[l][k].begin();
				st[l][k].erase(at);
				used.emplace(at.fi);
				l = at.fi.back() - '0';
				nice = true;
			}
		}

		if (nice) continue;

		nice = false;
		for (int k = 0; !nice && k < 2; k++) {
			if (st[k][l].size()) {
				pair<string, int> at = *st[k][l].begin();
				if (used.count(rev[at.se])) continue;
				st[k][l].erase(at);
				used.emplace(rev[at.se]);
				ans.emplace(at.se);
				l = at.fi.front() - '0';
				nice = true;
			}
		}

		ok = nice;
	}

	return ans;
}

void _solve() {
	cin >> n;
	a = vector<string>(n);
	rev = vector<string>(n);

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) st[i][j].clear();

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		rev[i] = a[i];
		reverse(rev[i].begin(), rev[i].end());

		int f = a[i].front() - '0';
		int b = a[i].back() - '0';
		st[f][b].emplace(a[i], i);
	}

	bool ok1, ok2;
	set<int> ans1 = solve(0, ok1), ans2 = solve(1, ok2);

	set<int> ans;
	if (ok1 && ok2) ans = ans1.size() < ans2.size() ? ans1 : ans2;
	else if (ok1) ans = ans1;
	else if (ok2) ans = ans2;
	else {
		cout << -1 << '\n';
		return;
	}

	cout << ans.size() << '\n';
	for (int i : ans) cout << i+1 << ' ';
	cout << '\n';

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();
	return 0;
}