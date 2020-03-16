#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pii> a[MAXN];
vector<pii> each[MAXN]; // each[x] = {y, time}
vector<int> calc[MAXN]; // todos os caras pra calcular o x
int ans[MAXN];
int ind[MAXN];

vector<pii> mp[MAXN];
vector<pii> cur[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < MAXN; i++) a[i].eb(0, 0);

	int q; cin >> q;
	int qttAns = 0;

	vector<int> all;
	for (int i = 1; i <= q; i++) {
		int op, x, y; cin >> op >> x >> y;
		if (op == 1) a[x].eb(i, y);
		else {
			qttAns++;
			ind[i] = qttAns;
			each[x].eb(y, i);
			calc[x].eb(y);
			all.eb(x);
		}
	}

	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	for (int i : all) {
		sort(calc[i].begin(), calc[i].end());
		calc[i].erase(unique(calc[i].begin(), calc[i].end()), calc[i].end());

		for (auto p : each[i]) mp[p.fi].eb(p.se, 0);
		for (auto p : calc[i]) sort(mp[p].begin(), mp[p].end());

		for (int j = 0; j < MAXN; j += i) {
			for (auto k : calc[i]) {
				if (j + k >= MAXN) continue;
				for (auto val : a[j + k]) {
					auto it = lower_bound(mp[k].begin(), mp[k].end(), mk(val.fi, 0));
					if (it != mp[k].end())
						it->se += val.se;
				}
			}
		}

		for (auto p : calc[i]) {
			int last = 0;
			for (auto pp : mp[p]) {
				ans[ind[pp.fi]] = pp.se + last;
				last = ans[ind[pp.fi]];
			}
			mp[p].clear();
		}
	}

	for (int i = 1; i <= qttAns; i++) cout << ans[i] << '\n';

	return 0;
}