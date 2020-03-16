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
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;

	vector<vector<int> > ans;

	while(s.size()) {
		vector<int> cur;

		int sl = 0, ord = 1;

		vector<int> opn, cls;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '(') opn.eb(i);
			else cls.eb(i);
		}

		for (int i = 0, j = (int) cls.size() - 1; i < (int)opn.size() && j >= 0; i++, j--) {
			if (opn[i] < cls[j]) {
				cur.eb(opn[i]);
				cur.eb(cls[j]);
			} else break;
		}

		if (cur.size() == 0) break;
		sort(cur.begin(), cur.end());
		ans.pb(cur);

		string t = s;
		s.clear();
		for (int i = 0, c = 0; i < (int)t.size(); i++) {
			if (c < (int)cur.size() && i == cur[c]) c++;
			else s += t[i];
		}
	}

	cout << ans.size() << '\n';
	for (auto& _v : ans) {
		cout << _v.size() << '\n';
		for (auto& _x : _v) cout << _x + 1 << ' ';
		cout << '\n';
	}

	return 0;
}